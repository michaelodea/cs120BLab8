/*              Name & E-mail: Michael O'Dea, mode001@ucr.edu
 *              Lab Section: 025
 *              Assignment: Lab #8  Exercise #4
 *              Exercise Description: Design a system, using a bank of eight 
 *              LEDs, where the number of LEDs illuminated is a representation
 *              of how much light is detected. For example, when more light 
 *              is detected, more LEDs are illuminated. Criteria: The LEDs 
 *              should illuminated in sequence from 0 to 7, based on the 
 *              amount of light detected by the photoresistor.
 *
 *
 *              I acknowledge all content contained herein, excluding 
 *              template or example code, is my own original work.
 */


//DEMO: https://drive.google.com/open?id=1AcuIomZCU5HzT3M7mjGQp7Sy0Zw-eohD

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
	
	unsigned char num = 0x00;

	ADC_init();

    	while(1){

		if(ADC <= 420 && ADC >= 370){
                        num = 0xFF;
                }
                else if(ADC <= 369 && ADC >= 320){
                        num = 0xFE;
                }
                else if(ADC <= 319 && ADC >= 270){
                        num = 0xFC;
                }
                else if(ADC <= 269 && ADC >= 220){
                        num = 0xF8;
                }
                else if(ADC <= 219 && ADC >= 170){
                        num = 0xF0;
                }
                else if(ADC <= 169 && ADC >= 120){
                        num = 0xE0;
                }
                else if(ADC <= 129 && ADC >= 80){
                        num = 0xC0;
                }
                else if(ADC <= 89 && ADC >= 0){
                        num = 0x80;
                }
                PORTB = num;
    	}

return 1;

}


