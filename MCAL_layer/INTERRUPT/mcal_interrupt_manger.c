/* 
 * File:   mcal_interrupt_manger.c
 * Author: YaseenEzzat
 *
 * Created on November 1, 2023, 10:03 AM
 */

#include "mcal_interrupt_manger.h"

void __interrupt()Interrupt_Manger_high(void){
   if((INTCONbits.INT0F==INTERRUPT_FLAG_BIT_HIGH)&&(INTCONbits.INT0E==INTERRUPT_ENABLE)) 
   {
       
       ISR_INT0 ();
   }
   else if((INTCON3bits.INT1F==INTERRUPT_FLAG_BIT_HIGH)&&(INTCON3bits.INT1E==INTERRUPT_ENABLE)) 
   {
       
       
        ISR_INT1 ();
   }
   else if((INTCONbits.RBIF==INTERRUPT_FLAG_BIT_HIGH)&&(INTCONbits.RBIE==INTERRUPT_ENABLE)) 
   {
       
        ISR_RB();
   }
   else if((PIR1bits.ADIF==INTERRUPT_FLAG_BIT_HIGH)&&(PIE1bits.ADIE==INTERRUPT_ENABLE)) 
   {
       
        ISR_ADC();
   }
   else if((INTCONbits.TMR0IF==INTERRUPT_FLAG_BIT_HIGH)&&(INTCONbits.TMR0IE==INTERRUPT_ENABLE)) 
   {
       ISR_TIMER0();
      
   }
   else if((PIR1bits.TMR1IF==INTERRUPT_FLAG_BIT_HIGH)&&(PIE1bits.TMR1IE==INTERRUPT_ENABLE)) 
   {
       ISR_TIMER1();
      
   }
   else if((PIR1bits.TMR2IF==INTERRUPT_FLAG_BIT_HIGH)&&(PIE1bits.TMR2IE==INTERRUPT_ENABLE)) 
   {
       ISR_TIMER2();
      
   }
   else if((PIR2bits.TMR3IF==INTERRUPT_FLAG_BIT_HIGH)&&(PIE2bits.TMR3IE==INTERRUPT_ENABLE)) 
   {
       ISR_TIMER3();
      
   }
   else if((PIR1bits.CCP1IF==INTERRUPT_FLAG_BIT_HIGH)&&(PIE1bits.CCP1IE==INTERRUPT_ENABLE)) 
   {
       ISR_CCP1();
      
   }
   else if((PIR1bits.TXIF==INTERRUPT_FLAG_BIT_HIGH)&&(PIE1bits.TXIE==INTERRUPT_ENABLE)) 
   {
       ISR_USART_Trans();
      
   }
   else if((PIR1bits.RCIF==INTERRUPT_FLAG_BIT_HIGH)&&(PIE1bits.RCIE==INTERRUPT_ENABLE)) 
   {
       ISR_USART_Receive();
      
   }
   else if((PIR1bits.SSPIF==INTERRUPT_FLAG_BIT_HIGH)&&(PIE1bits.SSPIE==INTERRUPT_ENABLE)) 
   {
       ISR_SPI();
      
   }
      else {/*nothing*/}
   
}
void __interrupt(low_priority)Interrupt_Manger_low(void){
   if((INTCON3bits.INT2F==INTERRUPT_FLAG_BIT_HIGH)&&(INTCON3bits.INT2E==INTERRUPT_ENABLE)) 
   {
       
        ISR_INT2 ();
   }
   
   
   else {/*nothing*/}
}