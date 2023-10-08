#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

struct LED{
	LED();
	void LED_toggle();
};

LED::LED(){
	DDRA= 0xff;
	PORTA = 0x00;
}

void LED::LED_toggle(){
	_delay_ms(500);
	PORTA = ~PORTA;
}
int main(){
	
	LED led;
	while(1){
		led.LED_toggle();
	}
	return 0;
}