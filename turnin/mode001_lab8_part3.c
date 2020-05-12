/*              Name & E-mail: Michael O'Dea, mode001@ucr.edu
 *              Lab Section: 025
 *              Assignment: Lab #8  Exercise #3
 *              Exercise Description:Design a system where an LED is 
 *              illuminated only if enough light is detected from the photo 
 *              resistor. Criteria: If the result of the ADC is >= MAX/2, the 
 *              LED is illuminated. If the result of the ADC is < MAX/2, 
 *              the LED is turned off. Nwote: MAX is the highest ADC value 
 *              observed from exercise 2 of the lab.
 *
 *
 *              I acknowledge all content contained herein, excluding 
 *              template or example code, is my own original work.
 */


//DEMO: https://drive.google.com/open?id=1AUzltIMpmJHQLWtbmuO_SlvWCR-eGLMD

#ifdef _SIMULATE_
#include <avr/io.h>
#include <simAVRHeader.h>
#endif

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

	
int main(void){	
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	ADC_init();

    	while(1){
		if(ADC >= 208){
			PORTB = 0x01;
		}
		else{
			PORTB = 0x00;
		}
    	}

return 1;

}


