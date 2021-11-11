#include <msp430.h> 

#define RedLED BIT6;
#define GreenLED BIT0;

int main(void)
{
	BCSCTL2 |= DIVS_3; //Use SMCLK (initial frequency of 1MHZ), 1MHZ/8 = 125KHz
			   //Desired clock to be 1/256ms = 3.9KHz
	WDTCTL = WDT_MDLY_32; //125k/3.9k = 32.05 == WDT_MDLY_32 WDTPW+WDTTMSEL+WDTCNTCL
	IE1 |= WDTIE; //Enable WDT interrupt

	P1DIR = 0x41; //Set both LEDs as outputs
	P1OUT = RedLED; //Initiate with Red LED on

	_enable_interrupts();
	LPM1; //Low Power Mode 1
}
#pragma vector=WDT_VECTOR
__interrupt void WDT(void)
{
    P1OUT ^= 0x41; //toggle the LEDs
}
