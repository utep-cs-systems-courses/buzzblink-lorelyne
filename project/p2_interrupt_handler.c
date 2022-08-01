#include <msp430.h>
#include "switches.h"

/*Switch on P2*/
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES){ /*if button causes interrupt*/
    P2IFG &= ~SWITCHES;  /*clear pending sw interrupts*/
    switch_interrupt_handler(); /*single handler for all switches*/ 
 }
}
