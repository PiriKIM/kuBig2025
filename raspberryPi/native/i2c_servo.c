#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define RGB_SERVO_I2C_ADDR 0x5e
#define PCA9685_LED_ON_L 0x06
#define PCA9685_PRESCALE 0xFE
#define PCA9685_MODE1 0x00

void i2C_init(int fd, int freq);

int main(void)
{
    wiringPiSetupGpio();
    int rgb_servo_fd = wiringPiI2CSetup(RGB_SERVO_I2C_ADDR);
    i2C_init(rgb_servo_fd, 50); // 50 Hz
    // 프리스케일 값 = (오실레이터 주파수 / (4096 * 원하는 주파수)) - 1
    // 25000000 / (4096 * (0x79 + 1))=50.028817

    int servo_0 = 120;
    int servo_90 = 307;
    int servo_180 = 500;
    
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 12, 0);          // Servo1 on_off
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 16, 0);          // Servo2 on_off

    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 14, servo_0);    // Servo1 pwm duty
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 18, servo_0);    // Servo2 pwm duty
    delay(500);

    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 14, servo_90);    // Servo1 pwm duty
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 18, servo_90);    // Servo2 pwm duty
    delay(500);

    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 14, servo_180);    // Servo1 pwm duty
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 18, servo_180);    // Servo2 pwm duty
    delay(500);

    // free
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 14, 0);    // Servo1 pwm duty
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 18, 0);    // Servo2 pwm duty

    return 0;
}

void i2C_init(int fd, int freq)
{
    int prescale = (int)(25000000.0 / (4096.0 * freq) - 1.0 + 0.5);
    printf("%d, 0x%x\n", prescale, prescale);
    wiringPiI2CWriteReg8(fd, PCA9685_MODE1, 0x10);          // SLEEP 모드 진입
    delay(5); // 모드 변경 후 안정화 대기
    wiringPiI2CWriteReg8(fd, PCA9685_PRESCALE, prescale);   // 주파수 설정
    wiringPiI2CWriteReg8(fd, PCA9685_MODE1, 0x00);          // SLEEP 해제
    delay(5); // 모드 변경 후 안정화 대기
    wiringPiI2CWriteReg8(fd, PCA9685_MODE1, 0xA1);          // Auto-Increment 활성화
}