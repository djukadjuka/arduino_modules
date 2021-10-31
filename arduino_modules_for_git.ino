#if !defined(__PROJECT_H)
#define __PROJECT_H

#include <string.h>

#include "state_machine.h"

StateMachine state_machine;

void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);

    state_machine.init_pins();
}
  
void loop() {
	state_machine.update_reset();
	state_machine.update();
}

#endif // __PROJECT_H
