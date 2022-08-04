#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"


static char led_state = 0;

/*as button is pressed, we increment to 3 starting from 0*/
void toggle_red(){
  red_on = 1;
  green_on = 0;
  led_changed = 1;
  led_update();
  buzzer_set_period(0);
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

static char blink_count = 0;
static char buzzCount = 0;
void imp()
{
   if(++buzzCount == 65){ //250 time per sec
      imperialSound();
      buzzCount=0;
    }
}

/*
  Dimming led pattern functions
*/
static int blinkLimit = 0;    // state var representing reciprocal of duty cycle 
void blinkUpdate()            // called every 1/250s to blink with duty cycle 1/blinkLimit
{
  static int blinkCount = 0;  // state var representing blink state
  if (blinkCount++ >= blinkLimit) {
    blinkCount = 0;
    greenControl(1);
  } else
    greenControl(0);
}

void oncePerSecond() // repeatedly start bright and gradually lower duty cycle, one step/sec
{
  static unsigned short period_inc = 1000;

  if (++blinkLimit >= 8) {  // but don't let duty cycle go below 1/7.
    blinkLimit = 0;
    if (red_on)
      curr_period = 0;      // reset buzzer period
    change_red();
  }
  curr_period += period_inc;
  buzzer_set_period(curr_period);
}

void secondUpdate()  // called every 1/250 sec to call oncePerSecond once per second
{
  static int secondCount = 0; // state variable representing repeating time 0…1s
  if (secondCount++ >= 250) { // once each second
    secondCount = 0;
    oncePerSecond();
  }
}

void dimming_state_machines()
{
    buzzer_set_period(100);
    
    blinkUpdate();
    secondUpdate();

}


/*
  Turn leds off and stop buzzing
*/
void off_leds_buzzer()
{
  led_off();
  buzzer_set_period(100);
}

