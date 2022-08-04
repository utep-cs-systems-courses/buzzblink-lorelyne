#include "switches.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "select_SM.h"

void select_SM()
{
static char blink_count = 0;
static char buzzCount = 0;
  switch (n_switch_down) {
  case 1:   //Alternate between toggling red & green
    toggle_red();
    break;
  case 2:   //Dim green light, toggle red light and update buzz
    dimming_state_machines();
    break;
  case 3:   //Go from a high to low frequency at different rates
    imp();
    break;
  case 4:   //Turn leds off and stop buzzer
  default:
    off_leds_buzzer();
  }
}

