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
    int rgb_servo_fd = wiringPiI2CSetup(RGB_SERVO_I2C_ADDR);
    i2C_init(rgb_servo_fd, 1000); // 1 KHz
    // i2C_init(rgb_servo_fd, 0x1F); // 200 Hz
    // i2C_init(rgb_servo_fd, 0x79); // 50 hz
    // 프리스케일 값 = (오실레이터 주파수 / (4096 * 원하는 주파수)) - 1
    // 25000000 / (4096 * (0x79 + 1))=50.028817
    srand(time(NULL)); // random 셋

    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L, 0);     // 빨간색
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 4, 0); // 녹색
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 8, 0); // 파란색

    // 빨간색
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 2, 4095);
    delay(100);
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 2, 0);
    delay(100);

    // 녹색
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 6, 4095);
    delay(100);
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 6, 0);
    delay(100);

    // 파란색
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 10, 4095);
    delay(100);
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 10, 0);
    delay(100);

    // 점점 밝아지는 코드
    for (int i = 0; i < 4096; ++i)
    {
        wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 2, i);
        wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 6, i);
        wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 10, i);
        delay(1);
    }
    // 랜덤한 색깔
    for (int i = 0; i < 100; ++i)
    {
        wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 2, rand() % 4096);
        wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 6, rand() % 4096);
        wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 10, rand() % 4096);
        delay(100);
    };
    // 모든 LED OFF
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 2, 0);
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 6, 0);
    wiringPiI2CWriteReg16(rgb_servo_fd, PCA9685_LED_ON_L + 10, 0);

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