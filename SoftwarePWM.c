#include <msp430.h> 

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;               //Stop WDT
    P1DIR |= BIT6;                          //P1.6 set for output
    P1OUT = 0x00;                           //Clear outputs

    P1SEL |= BIT6;                          //select TA0.1 output signal

    TACCR0 = 62500-1;                        //PWM Time Period/ frequency, (F+T)/D - 1, (1000000+0.5)/8 - 1
    TACCTL1 = OUTMOD_7;                     //Active PWM signal at high state
    TACCR1 = 6250-1;                        //Duty cycle to 10%
    TACTL = TASSEL_2 + ID_3 + MC_1;         //TASSEL_2 = SMCLK, ID_3 = CLK divider = 8, Clock counts up mode

    while(1);
}
