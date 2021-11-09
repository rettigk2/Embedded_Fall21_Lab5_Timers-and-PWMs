#include <msp430.h> 

#define BUTTON1 BIT1

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;  // Stop WDT

    P1DIR |= BIT6;             //Set Red LED as output
    P1SEL |= BIT6;             //Red LED on timer mode for PWM

    TACCR0 = 31250-1;                        //PWM Time Period/ frequency, (F+T)/D - 1, (1000000+0.250)/8 - 1
    TACCTL1 = OUTMOD_7;                     //Active PWM signal at high state
    TACCR1 = 6250-1;                        //Duty cycle to 20%
    TACTL = TASSEL_2 + ID_3 + MC_1;         //TASSEL_2 = SMCLK, ID_3 = CLK divider = 8, Clock counts up mode

    _enable_interrupts(); // Enter LPM0
}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{

}