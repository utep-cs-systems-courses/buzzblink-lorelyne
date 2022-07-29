#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h"
#include "led.h"
#include "switches.h"

void __interrupt_vec(WDT_VECTOR) WDT(){

  static char blink_count = 0;
  static char buzzCount = 0;
  
   if(++buzzCount == 65 && musicSwi == 1){ //250 time per sec 
      imperialSound();
      buzzCount=0;
    }else if(musicSwi == 2){
      buzzer_set_period(0);
    }
}
