/*              Name & E-mail: Michael O'Dea, mode001@ucr.edu
 *              Lab Section: 025
 *              Assignment: Lab #8  Exercise #1 
 *              Exercise Description: Make sure your breadboard is wired 
 *              according to the prelab. The potentiometer is used to adjust 
 *              the voltage supplied to the microcontroller for ADC . Design 
 *              a system that reads the 10-bit ADC result from the ADC 
 *              register, and displays the result on a bank of 10 LEDs.
 *
 *
 *              I acknowledge all content contained herein, excluding 
 *              template or example code, is my own original work.
 */

//DEMO: https://drive.google.com/open?id=1AH_MUzIalKSC3Lp7VQnmSxCJrrqhoIPm

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


