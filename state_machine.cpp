#include "state_machine.h"

StateMachine::StateMachine(){
    this->last_update_millis = 0;
    this->last_update_millis_reset = 0;

    this->current_state = SS_INIT;
    this->last_state = SS_INIT;

    this->current_state_reset = SS_RESET;
    this->last_state_reset = SS_RESET;
};


void StateMachine::init_pins(){
    // TODO: Init pins
}

void StateMachine::reset(){
    // TODO: Reset modules
}

String StateMachine::to_string(){

}

void StateMachine::change_state(int next_state){
    this->last_state = this->current_state;
    this->current_state = next_state;
    this->last_update_millis = millis();
};

void StateMachine::update(){
    // If the state machine is not either in delay or in starting state, do not update state machine
    if(this->current_state_reset != SS_RESET ||
    this->current_state_reset != S_RESET_DELAY){
        return;
    }

    // Grab current millis
    unsigned int current_millis = millis();

    // Begin state logic
    if(SS_INIT == this->current_state){
        // ...
    }
};

void StateMachine::change_state_reset(int next_state){
    this->last_state = this->current_state;
    this->current_state = next_state;
    this->last_update_millis = millis();
}

void StateMachine::update_reset(){
    unsigned long current_millis = millis();

    if(SS_RESET == this->current_state_reset){
        // Add some sort of check for moving to next reset state
        /*
        if(...){
            this->change_state_reset(S_RESET_DELAY);
        }
        */
    }
    else if(S_RESET_DELAY == this->current_state_reset){
        if(current_millis - this->last_update_millis_reset){
            this->change_state_reset(S_RESET_REAL);
        }
    }
    else if(S_RESET_REAL == this->current_state_reset){
        // Reset all modules here, do other
        // reset things (maybe update lcd screen ...)
        // Return to start reset state
        this->change_state_reset(SS_RESET);
    }
};
