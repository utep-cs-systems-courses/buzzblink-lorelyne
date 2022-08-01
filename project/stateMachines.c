#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"

static char count = 0;

/*as button is pressed, we increment to 3 starting from 0*/
void countToThree(){

  switch(count){
  case 0:
   buzzer_set_period(1000);
   red_on = 0;
   green_on = 0;
   count = 1;
   break;

     case 1:
   buzzer_set_period(800);
   red_on = 1;
   green_on = 0;
   count = 2;
   break;

  case 2:
   buzzer_set_period(600);
   red_on = 0;
   green_on = 1;
   count = 3;
   break;

  case 3:
   buzzer_set_period(400);
   red_on = 1;
   green_on = 1;
   count = 0;
   break;
  }
  led_changed = 1;
  led_update();
}

static char secCount = 0;
static int  buzzerSound = 0;

void imperialSound(){
  switch(secCount){
  case 0:
    buzzerSound = 704;
    secCount = 1;
    red_on = 0;
    green_on = 1;
    break;

    case 1:
    buzzerSound = 0;
    secCount = 2;
    break;
  case 2:
    buzzerSound = 704;
    secCount = 3;
    red_on = 1;
    green_on = 0;
    break;
  case 3:
    buzzerSound = 0;
    secCount = 4;
    break;
  case 4:
    buzzerSound = 704;
    secCount = 5;
    red_on = 0;
    green_on = 1;
    break;
  case 5:
    buzzerSound = 0;
    secCount = 6;
    break;
   case 6:
     buzzerSound = 1674;
     secCount = 7;
     red_on = 1;
     green_on = 0;
     break;
   case 7:
     buzzerSound = 0;
     secCount = 0;
     break;

     case 8:
     buzzerSound = 1184;
     secCount = 9;
     red_on = 0;
     green_on = 1;
     break;
  case 9:
    buzzerSound = 0;
    secCount = 10;
    break;
  case 10:
    buzzerSound = 704;
    secCount = 11;
    red_on = 1;
    green_on = 0;
    break;
  case 11:
    buzzerSound = 0;
    secCount = 0;
    break; 
  }
  buzzer_set_period(buzzerSound);
  led_changed = 1;
  led_update();
}

/*dims lights to 75%, as we call dimLights() really fast through the wdInterrupt one state
will be off as to achieve the desired effect of 75%*/
void dimLights()
{
  static char state = 0;
  switch(state){
  case 0:
    red_on = 1;
    green_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 1;
    green_on = 1;
    state = 2;
    break;
  case 2:
    red_on = 1;
    green_on = 1;
    state = 3;
    break;
  case 3:
    red_on = 0; /*lights are both off for one state*/
    green_on = 0;
    state = 0;
    break;
  }
}
void rest(){
  buzzer_set_period(0);
  count = 0;
  red_on = 0;
  green_on = 0;
  led_changed = 1;
  led_update();
}
