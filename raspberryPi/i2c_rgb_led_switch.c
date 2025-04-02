// 내가한거
// 스위치 1, 2, 3을 이용해서
// 1 -> R 색 변화
// 2 -> G 색 변화
// 3 -> B 색 변화
// 스위치를 오래 누르면(0 ~ 1 초) -> (0 ~ 4095) 높은 값으로 변화할 수 있게 만들기

#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define RGB_SERVO_I2C_ADDR 0x5e
#define PCA9685_LED_ON_L 0x06
#define PCA9685_PRESCALE 0xFE
#define PCA9685_MODE1 0x00

#define SW1 4
#define SW2 17
#define SW3 27
#define SW4 22

void SW_ISR4(void);
void i2C_init(int fd, int freq);

int pre_push_time, cur_push_time;
int r_value = 0, g_value = 0, b_value = 0;
int count_flag = 1;

int main(void)
{
    int rgb_servo_fd = wiringPiI2CSetup(RGB_SERVO_I2C_ADDR);
    i2C_init(rgb_servo_fd, 1000); // 1 KHz

    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L, 0);     // 빨간색
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 4, 0); // 녹색
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 8, 0); // 파란색

    wiringPiISR(SW4, INT_EDGE_FALLING, SW_ISR4);

    while (1)
    {
        if (count_flag)
        {
            // RED
            if ((digitalRead(SW1) == HIGH) && r_value < 4095)
                r_value++;
            else if ((digitalRead(SW1) == LOW) && r_value > 0)
                r_value--;
            // GREEN
            if ((digitalRead(SW2) == HIGH) && g_value < 4095)
                g_value++;
            else if ((digitalRead(SW2) == LOW) && g_value > 0)
                g_value--;
            // BLUE
            if ((digitalRead(SW3) == HIGH) && b_value < 4095)
                b_value++;
            else if ((digitalRead(SW3) == LOW) && b_value > 0)
                b_value--;
        }
        // RGB LED ON
        wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 2, r_value);
        wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 6, g_value);
        wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 10, b_value);
        // printf("R: %d, G: %d, B: %d\n", r_value, g_value, b_value);
        delay(2);
    }
    
    // 모든 LED OFF
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 2, 0);
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 6, 0);
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 10, 0);

    return 0;
}

void i2C_init(int fd, int freq)
{
    wiringPiSetupGpio();

    int sw[4] = {SW1, SW2, SW3, SW4};

    for (int i = 0; i < 4; i++)     // PIN 입출력 설정
    {
        pinMode(sw[i], INPUT);
        // pullUpDnControl(sw[i], PUD_UP);  // 풀업 저항 설정
    }

    int prescale = (int)(25000000.0 / (4096.0 * freq) - 1.0 + 0.5);
    // printf("%d, 0x%x\n", prescale, prescale);

    wiringPiI2CWriteReg8(fd, PCA9685_MODE1, 0x10);          // SLEEP 모드 진입
    delay(5); // 모드 변경 후 안정화 대기
    wiringPiI2CWriteReg8(fd, PCA9685_PRESCALE, prescale);   // 주파수 설정
    wiringPiI2CWriteReg8(fd, PCA9685_MODE1, 0x00);          // SLEEP 해제
    delay(5); // 모드 변경 후 안정화 대기
    wiringPiI2CWriteReg8(fd, PCA9685_MODE1, 0xA1);          // Auto-Increment 활성화

    cur_push_time = millis();
    pre_push_time = cur_push_time;
}

void SW_ISR4(void)
{
    pre_push_time = cur_push_time;
    cur_push_time = millis();

    unsigned int double_time = cur_push_time - pre_push_time;
    if (double_time < 500)  // 500ms 이내에 더블 클릭 시 RGB LED OFF
    {
        r_value = 0;
        g_value = 0;
        b_value = 0;
        count_flag = 1;
    }
    else                    // 더블 클릭 아니면 밝기 카운트 시작 또는 멈춤
    {
        if (count_flag)
            count_flag = 0;
        else
            count_flag = 1;
    }
}