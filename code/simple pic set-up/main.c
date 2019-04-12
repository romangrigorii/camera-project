#include <xc.h>
#include "NU32.h"
#include "pulses.h"

int i=1, dt = 0;
char message[100];

int main(){
  NU32_Startup();
  __builtin_disable_interrupts();
  init();
  AU = 0;
  SH = 0;
  __builtin_enable_interrupts();
  while (1){
  }
}
