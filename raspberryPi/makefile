TARGET = helloRaspberry switch_led interrupt
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