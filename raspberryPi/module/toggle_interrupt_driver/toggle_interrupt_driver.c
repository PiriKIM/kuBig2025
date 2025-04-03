#include <linux/fs.h>
#include <linux/gpio.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/kernel.h>
#include <linux/module.h>

#define DEV_MAJOR_NUMBER 224
#define DEV_NAME "toggle_interrupt_driver"
#define SW1 59
#define SW2 60
#define SW3 61
#define SW4 57

static int toggle_interrupt_driver_open(struct inode *inode, struct file *file);
static int toggle_interrupt_driver_release(struct inode *inode, struct file *file);
static ssize_t toggle_interrupt_driver_write(struct file *file, const char __user *buf, size_t length, loff_t *ofs);
static ssize_t toggle_interrupt_driver_read(struct file *file, char __user *buf, size_t length, loff_t *ofs);
irqreturn_t irq_handler(int irq, void *dev_id);

static int led[4] = {23 + 512, 24 + 512, 25 + 512, 1 + 512};
static int sw[4] = {4 + 512, 17 + 512, 27 + 512, 22 + 512};
static int led_status[4] = {0};

static struct file_operations toggle_interrupt_driver_fops = {
    .owner = THIS_MODULE,
    .open = toggle_interrupt_driver_open,
    .release = toggle_interrupt_driver_release,
    .write = toggle_interrupt_driver_write,
    .read = toggle_interrupt_driver_read
};

static int toggle_interrupt_driver_open(struct inode *inode, struct file *file)
{
    int ret;

    printk(KERN_INFO "led_driver_open!\n");
    for (int i = 0; i < 4; i++)
    {
        ret = gpio_request(led[i], "LED");
        if (ret < 0)
            printk(KERN_INFO "led driver %d request failed!\n", i);
    }

    printk(KERN_INFO "switch_driver_open!\n");
    for (int i = 0; i < 4; i++)
    {
        ret = gpio_request(sw[i], "SW");
        if (ret < 0)
            printk(KERN_INFO "switch driver %d request failed!\n", i);
    }

    printk(KERN_INFO "irq_driver_open!\n");
    for (int i = 0; i < 4; i++)
    {
        ret = request_irq(gpio_to_irq(sw[i]), (irq_handler_t)irq_handler, IRQF_TRIGGER_RISING, "IRQ", (void *)irq_handler);
        if (ret < 0)
            printk(KERN_INFO "irq driver %d request failed!\n", i);
    }

    return 0;
}
static int toggle_interrupt_driver_release(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "led_driver_release!\n");
    for (int i = 0; i < 4; i++)
    {
        gpio_free(led[i]);
    }

    printk(KERN_INFO "switch_driver_release!\n");
    for (int i = 0; i < 4; i++)
    {
        gpio_free(sw[i]);
    }

    printk(KERN_INFO "irq_driver_release!\n");
    for (int i = 0; i < 4; i++)
    {
        free_irq(gpio_to_irq(sw[i]), (void *)irq_handler);
    }

    return 0;
}
static ssize_t toggle_interrupt_driver_write(struct file *file, const char __user *buf, size_t length, loff_t *ofs)
{
    int ret;
    unsigned char cbuf[4];
    ret = copy_from_user(cbuf, buf, length);
    if (ret < 0)
        printk(KERN_INFO "lcopy from user error!\n");
    printk(KERN_INFO "toggle_interrupt_driver_write!\n");
    for (int i = 0; i < 4; i++)
    {
        ret = gpio_direction_output(led[i], cbuf[i]);
        if (ret < 0)
            printk(KERN_INFO "led driver %d direction output failed!\n", i);
    }
    return 0;
}
static ssize_t toggle_interrupt_driver_read(struct file *file, char __user *buf, size_t length, loff_t *ofs)
{
    int ret;
    char read_buf[4];
    printk(KERN_INFO "toggle_interrupt_driver_read!\n");
    
    for (int i = 0; i < 4; i++)
        read_buf[i] = led_status[i];

    ret = copy_to_user(buf, read_buf, sizeof(read_buf));
    if (ret < 0)
        printk(KERN_INFO "switch driver copy to user failed!\n");

    return 0;
}

irqreturn_t irq_handler(int irq, void *dev_id)
{
    printk(KERN_INFO "Debug %d\n", irq);

    switch (irq)
    {
    case SW1:
        if (led_status[0])
            led_status[0] = 0;
        else
            led_status[0] = 1;
        gpio_set_value(led[0], led_status[0]);
        break;
    case SW2:
        if (led_status[1])
            led_status[1] = 0;
        else
            led_status[1] = 1;
        gpio_set_value(led[1], led_status[1]);
        break;
    case SW3:
        if (led_status[2])
            led_status[2] = 0;
        else
            led_status[2] = 1;
        gpio_set_value(led[2], led_status[2]);
        break;
    case SW4:
        if (led_status[3])
            led_status[3] = 0;
        else
            led_status[3] = 1;
        gpio_set_value(led[3], led_status[3]);
        break;
    }

    return 0;
}

static int toggle_interrupt_driver_init(void)
{
    printk(KERN_INFO "toggle_interrupt_driver_init!\n");

    register_chrdev(DEV_MAJOR_NUMBER, DEV_NAME, &toggle_interrupt_driver_fops);

    return 0;
}

static void toggle_interrupt_driver_exit(void)
{
    printk(KERN_INFO "toggle_interrupt_driver_exit!\n");

    unregister_chrdev(DEV_MAJOR_NUMBER, DEV_NAME);
}

module_init(toggle_interrupt_driver_init);
module_exit(toggle_interrupt_driver_exit);
MODULE_LICENSE("GPL");
