# TARGET = helloRaspberry switch_led interrupt led_pwm soft_tone_buzzer hard_tone_buzzer i2c_rgb_led i2c_rgb_led2 i2c_rgb_led_switch i2c_rgb_led_switch2 i2c_servo fnd_control rgb_switch_fnd pir_control touch_ATQT1070 temp_humi gyro_control gyro_detector
TARGET = gyro_detector soft_tone_buzzer hard_tone_buzzer
all : ${TARGET}
CFLAGS = -lwiringPi

% : %.c
	cc -o $@ $< ${CFLAGS}

# helloRaspberry : 
# 	cc -o helloRaspberry helloRaspberry.c -lwiringPi

# switch_led : 
# 	cc -o switch_led switch_led.c -lwiringPi

# interrupt : 
# 	cc -o interrupt interrupt.c -lwiringPi

clean : 
	rm ${TARGET}