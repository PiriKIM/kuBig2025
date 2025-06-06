#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

void export_symbol_test_func1(void)
{
    printk(KERN_INFO "symbol test func1! None GPL License\n");
}
EXPORT_SYMBOL(export_symbol_test_func1);

void export_symbol_test_func2(void)
{
    printk(KERN_INFO "symbol test func2! GPL License\n");
}
EXPORT_SYMBOL(export_symbol_test_func2);
// EXPORT_SYMBOL_GPL(export_symbol_test_func2);

static int export_symbol_a_init(void)
{
    printk(KERN_INFO "export_symbol_a_init!\n");
    return 0;
}

static void export_symbol_a_exit(void)
{
    printk(KERN_INFO "export_symbol_a_exit!\n");
}

module_init(export_symbol_a_init);
module_exit(export_symbol_a_exit);
MODULE_LICENSE("GPL");