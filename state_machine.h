#if !defined(__STATE_MACHINE_H)
#define __STATE_MACHINE_H

#include "base_module.h"

// STATE DEFINITIONS
#define SS_INIT (0)

// RESET DEFINITIONS
#define SS_RESET (0)
#define S_RESET_DELAY (1)
#define S_RESET_REAL  (2)

// MILLISECOND DEFINITIONS
// Two seconds to reset
#define MS_RESET_DELAY (2000)

// OTHER DEFINITIONS (STR for LCD, ...)

class StateMachine: public BaseModule{
    // Fields
    unsigned int last_update_millis;
    unsigned int last_update_millis_reset;

    int current_state;
    int last_state;

    int current_state_reset;
    int last_state_reset;

	// Add modules here ...
	
public:
    void init_pins();

    void reset();

    String to_string();

    StateMachine();

    void update();

    void update_reset();

    void change_state(int next_state);

    void change_state_reset(int next_state);
}

#endif // __STATE_MACHINE_H
