#ifndef switches_included
#define switches_included

#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3

#define SWITCHES (SW1 | SW2 | SW3 | SW4)

void switch_init();
void switch_interrupt_handler();

extern unsigned short n_switch_down;
extern char switch_state_changed, bttnState, SW1down, SW2down, SW3down, SW4down, musicSwi;

#endif // included
