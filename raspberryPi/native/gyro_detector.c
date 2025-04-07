#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define GYRO_ADDR 0x68

// 자이로 센서 레지스트리
#define MPU6050_PWR_MGMT_1 0x6B
#define GYRO_CONFIG 0x1B
#define ACCEL_CONFIG 0x1C
#define ACCEL_XOUT_H 0x3B
#define GYRO_XOUT_H 0x43
// led 핀
#define LED1 23
#define LED2 24
#define LED3 25
#define LED4 1
// buzzer
#define BUZZER_PIN 12

int doReMi[8] = {523, 587, 659, 698, 783, 880, 987, 1046};
void setPWMFrequency(int freq);

typedef struct
{
    int32_t accel_x_offset;
    int32_t accel_y_offset;
    int32_t accel_z_offset;
    int32_t gyro_x_offset;
    int32_t gyro_y_offset;
    int32_t gyro_z_offset;
} Gyro_offset;

typedef struct
{
    int16_t ax;
    int16_t ay;
    int16_t az;
    int16_t gx;
    int16_t gy;
    int16_t gz;
} Gyro_data;

Gyro_offset init_gyro(int gyro_fd);
Gyro_data get_gyro(int gyro_fd);

int main(void)
{
    // MPU 6050 I2C file descriptor
    int gyro_fd = wiringPiI2CSetup(GYRO_ADDR);
    delay(100);
    wiringPiSetup(); // wiring pin 번호
    wiringPiSetupGpio(); // BCM 기준 gpio 핀번호
    
    int led[4] = {LED1, LED2, LED3, LED4};

    for (int i = 0; i < 4; ++i)
    {
        pinMode(led[i], OUTPUT);
    }
    
    pinMode(BUZZER_PIN, PWM_OUTPUT);

    Gyro_offset offset = init_gyro(gyro_fd);
    Gyro_data data;

    while (1)
    {
        data = get_gyro(gyro_fd);
        delay(100);
        if (data.ax - offset.accel_x_offset > 15000 && data.ax - offset.accel_x_offset < 17000)
        {
            //for (int i = 0; i < 8; ++i)
            //{
                printf("detect\n");
                setPWMFrequency(doReMi[0]);
                pwmWrite(BUZZER_PIN, 1000);
                digitalWrite(led[0], HIGH);
                delay(100);
                // digitalWrite(led[1], LOW);
                // delay(100);
            //}
        }
        // printf("ax: %f\t", ((float)data.ax - offset.accel_x_offset) / 16384.0);
        // printf("ay: %f\t", ((float)data.ay - offset.accel_y_offset) / 16384.0);
        // printf("az: %f\t", ((float)data.az - offset.accel_z_offset) / 16384.0);
        // printf("gx: %f\t", ((float)data.gx - offset.gyro_x_offset) / 131.0);
        // printf("gy: %f\t", ((float)data.gy - offset.gyro_y_offset) / 131.0);
        // printf("gz: %f\n", ((float)data.gz - offset.gyro_z_offset) / 131.0);
        delay(100);
    }

    return 0;
}

Gyro_offset init_gyro(int gyro_fd)
{
    // initiation MPU 6050
    wiringPiI2CWriteReg8(gyro_fd, MPU6050_PWR_MGMT_1, 0x00);    // 슬립 모드 해제
    wiringPiI2CWriteReg8(gyro_fd, GYRO_CONFIG, 0x00);           // 자리로 범위 250 도/s
    wiringPiI2CWriteReg8(gyro_fd, ACCEL_CONFIG, 0x00);          // 가속도 범위 +-2g
    delay(100);

    Gyro_offset offset;
    const int samples = 100;

    printf("test code4\n");
    for (int i = 0; i < samples; i++)
    {
        int16_t ax = (wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H) << 8) | wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 1);
        int16_t ay = (wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 2) << 8) | wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 3);
        int16_t az = (wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 4) << 8) | wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 5);
        int16_t gx = (wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H) << 8) | wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 1);
        int16_t gy = (wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 2) << 8) | wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 3);
        int16_t gz = (wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 4) << 8) | wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 5);

        offset.accel_x_offset += ax;
        offset.accel_y_offset += ay;
        offset.accel_z_offset += az;
        offset.gyro_x_offset += gx;
        offset.gyro_y_offset += gy;
        offset.gyro_z_offset += gz;
        delay(10);

        printf("test code5-%d\n", i);
    }

    offset.accel_x_offset /= samples;
    offset.accel_y_offset /= samples;
    offset.accel_z_offset /= samples;
    offset.accel_z_offset -= 16384;
    offset.gyro_x_offset /= samples;
    offset.gyro_y_offset /= samples;
    offset.gyro_z_offset /= samples;

    return offset;
}

Gyro_data get_gyro(int gyro_fd)
{
    Gyro_data data;

    data.ax = (wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H) << 8) | wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 1);
    data.ay = (wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 2) << 8) | wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 3);
    data.az = (wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 4) << 8) | wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 5);
    data.gx = (wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H) << 8) | wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 1);
    data.gy = (wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 2) << 8) | wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 3);
    data.gz = (wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 4) << 8) | wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 5);

    return data;
}

void setPWMFrequency(int freq)
{
    int range = 2000;
    int clock = 19200000 / (range * freq); // 19.2Mhz base clock
    pwmSetMode(PWM_MODE_MS);
    pwmSetRange(range);
    pwmSetClock(clock);
}


// //자이로센서 측정값의 변화단계(4단계)에 따른 부저 소리 및 led 출력 수 조절
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <wiringPi.h>
// #include <wiringPiI2C.h>
// #include <softTone.h>
// #include <math.h>
// #include <unistd.h>

// #define GYRO_ADDR 0x68
// #define SOUND_ADDR 0x1a

// // 자이로 센서 레지스트리 MPU6050
// #define MPU6050_PWR_MGMT_1 0x6B
// #define GYRO_CONFIG 0x1B
// #define ACCEL_CONFIG 0x1C
// #define ACCEL_XOUT_H 0x3B
// #define GYRO_XOUT_H 0x43

// #define LED1 23
// #define LED2 24
// #define LED3 25
// #define LED4 1
// #define BUZZER_PIN 12

// int doReMi[8] = {523, 587, 659, 698, 783, 880, 987, 1046};

// void setPWMFrequency(int freq); 

// int main(void)
// {
//     // MPU 6050 I2C file descriptor
//     int gyro_fd = wiringPiI2CSetup(GYRO_ADDR);
//     delay(100);
//     wiringPiSetup();
//     wiringPiSetupGpio(); 
//     pinMode(LED1, OUTPUT);
//     pinMode(LED2, OUTPUT);
//     pinMode(LED3, OUTPUT);
//     pinMode(LED4, OUTPUT);
//     pinMode(BUZZER_PIN, PWM_OUTPUT);

//     // initiation MPU 6050
//     wiringPiI2CWriteReg8(gyro_fd, MPU6050_PWR_MGMT_1, 0x00); // 슬립 모드 해제
//     wiringPiI2CWriteReg8(gyro_fd, GYRO_CONFIG, 0x00);        // 자이로 범위 250 도/s
//     wiringPiI2CWriteReg8(gyro_fd, ACCEL_CONFIG, 0x00);       // 가속도 범위 +-2g
//     delay(100);

//     const int samples = 100;

//     int32_t accel_x_offset = 0, accel_y_offset = 0, accel_z_offset = 0;
//     int32_t gyro_x_offset = 0, gyro_y_offset = 0, gyro_z_offset = 0;
//     for (int i = 0; i < samples; i++)
//     {
//         int16_t ax = (wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H) << 8) | wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 1);
//         int16_t ay = (wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 2) << 8) | wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 3);
//         int16_t az = (wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 4) << 8) | wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 5);
//         int16_t gx = (wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H) << 8) | wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 1);
//         int16_t gy = (wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 2) << 8) | wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 3);
//         int16_t gz = (wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 4) << 8) | wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 5);
//         accel_x_offset += ax;
//         accel_y_offset += ay;
//         accel_z_offset += az;
//         gyro_x_offset += gx;
//         gyro_y_offset += gy;
//         gyro_z_offset += gz;
//         delay(10);
//     }
//     accel_x_offset /= 100;
//     accel_y_offset /= 100;
//     accel_z_offset /= 100;
//     gyro_x_offset /= 100;
//     gyro_y_offset /= 100;
//     gyro_z_offset /= 100;
//     accel_z_offset -= 16384.0;

//     while (1)
//     {
//         int16_t ax = (wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H) << 8) | wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 1);
//         int16_t ay = (wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 2) << 8) | wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 3);
//         int16_t az = (wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 4) << 8) | wiringPiI2CReadReg8(gyro_fd, ACCEL_XOUT_H + 5);
//         int16_t gx = (wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H) << 8) | wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 1);
//         int16_t gy = (wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 2) << 8) | wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 3);
//         int16_t gz = (wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 4) << 8) | wiringPiI2CReadReg8(gyro_fd, GYRO_XOUT_H + 5);
//         int x = ((float)ax - accel_x_offset) / 16384.0 +((float)gx - gyro_x_offset) / 131.0;
//         int y = ((float)ay - accel_y_offset) / 16384.0 +((float)gy - gyro_y_offset) / 131.0;
//         int z = ((float)az - accel_z_offset) / 16384.0 +((float)gz - gyro_z_offset) / 131.0;
        
//         delay(100);
//         if(x+y+z > 40){
//             digitalWrite(LED1, HIGH);
//             digitalWrite(LED2, HIGH);
//             digitalWrite(LED3, HIGH);
//             digitalWrite(LED4, HIGH);
//             setPWMFrequency(doReMi[7]);
//             pwmWrite(BUZZER_PIN, 1000);
//         }else if(x+y+z > 30){
//             digitalWrite(LED1, HIGH);
//             digitalWrite(LED2, HIGH);
//             digitalWrite(LED3, HIGH);
//             digitalWrite(LED4, LOW);
//             setPWMFrequency(doReMi[5]);
//             pwmWrite(BUZZER_PIN, 1000);
//         }else if(x+y+z > 15){
//             digitalWrite(LED1, HIGH);
//             digitalWrite(LED2, HIGH);
//             digitalWrite(LED3, LOW);
//             digitalWrite(LED4, LOW);
//             setPWMFrequency(doReMi[3]);
//             pwmWrite(BUZZER_PIN, 1000);
//         }else if(x+y+z > 4){
//             digitalWrite(LED1, HIGH);
//             digitalWrite(LED2, LOW);
//             digitalWrite(LED3, LOW);
//             digitalWrite(LED4, LOW);
//             setPWMFrequency(doReMi[1]);
//             pwmWrite(BUZZER_PIN, 1000);
//         }else{
//             pwmWrite(BUZZER_PIN, 0);
//             digitalWrite(LED1, LOW);
//             digitalWrite(LED2, LOW);
//             digitalWrite(LED3, LOW);
//             digitalWrite(LED4, LOW);
//         }
//     }

//     return 0;
// }

// void setPWMFrequency(int freq){
//     int range = 2000;
//     int clock = 19200000 / (range * freq); // 라즈베리파이 기본 클럭이 19.2MHz된다
//     pwmSetMode(PWM_MODE_MS);
//     pwmSetRange(range); //쿨럭을 나누는 틱의 갯수
//     pwmSetClock(clock); // 
// }