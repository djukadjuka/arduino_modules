#if !defined(__PROJECT_H)
#define __PROJECT_H

#define TRUE (1)
#define FALSE (0)

#include "state_machine.h"

StateMachine state_machine;

void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);

    state_machine->init_pins();
}

void loop() {
	state_machine.UpdateResetModules();
	state_machine.Update();
}

#endif // __PROJECT_H
