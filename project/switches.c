#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "select_SM.h"

 /* effectively boolean */
char SW1down, SW2down, SW3down, SW4down, bttnState, musicSwi, switch_state_changed;
static char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void switch_init()		/* setup switch */
{
  P2REN |= SWITCHES;	/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;	/* pull-ups for switches */
  P2DIR &= ~SWITCHES;	/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

unsigned short n_switch_down = 0;
void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
    if((p2val & SW1) == 0){
        n_switch_down = 1;
    }else if ((p2val & SW2) == 0){
        n_switch_down = 2;
    }else if ((p2val & SW3) == 0){
        n_switch_down = 3;
    }else if ((p2val & SW4) == 0){
        n_switch_down = 4;
    }switch_state_changed = 1;
    select_SM(n_switch_down);
}

