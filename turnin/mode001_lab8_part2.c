/*              Name & E-mail: Michael O'Dea, mode001@ucr.edu
 *              Lab Section: 025
 *              Assignment: Lab #8  Exercise #2 
 *              Exercise Description: Revise exercise 1 by replacing the 
 *              potentiometer with a photoresistor and 330 ohm resistor. Take 
 *              note of the highest ADC value displayed (MAX) when the 
 *              photoresistor is exposed to light, and the lowest ADC value 
 *              displayed (MIN) when the photoresistor is deprived of all 
 *              light. These values will be used for the remaining lab 
 *              exercises.
 *
 *
 *              I acknowledge all content contained herein, excluding 
 *              template or example code, is my own original work.
 */


//DEMO: https://drive.google.com/open?id=1AQBZe55mdYms9pfMgZPW4WrkOf5afYj4

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
		unsigned short AD = ADC;
		PORTB =  (char)AD;
		PORTD = (char)(AD >> 8);
    	}

return 1;

}


