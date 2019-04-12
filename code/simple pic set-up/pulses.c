#include <xc.h>
#include "NU32.h"
#include "pulses.h"

int ii;
void wait(t){ // = 8 cycles + t cycles
  for (ii=0;ii<t;ii++){
  }
}

void init(){
  TRISBbits.TRISB11 = 0;
  TRISBbits.TRISB12 = 0;


  PR3 =  19999;
  TMR3 = 0;
  T3CONbits.TCKPS = 0; // = 1
  T3CONbits.ON = 1;
  IPC3bits.T3IP = 2;
  IPC3bits.T3IS = 0;
  IFS0bits.T3IF = 0;
  IEC0bits.T3IE = 1;
}

void __ISR(_TIMER_3_VECTOR,IPL4SOFT) Timer3ISR(void){
  AU = 1;
  wait(10);
  SH = 1;
  wait(40);
  SH = 0;
  wait(10);
  AU = 0;
  IFS0bits.T3IF = 0;
}
