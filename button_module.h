#if !defined(__BUTTON_MODULE_H)
#define __BUTTON_MODULE_H

#include "base_module.h"

#define BUTTON_STATE_PRESSED (1)

class ButtonModule: public BaseModule{
    int button_pin;
public:
    ButtonModule(int button_pin){
        this->button_pin = button_pin;
    }

    void init_pins(){
        pinMode(this->button_pin, INPUT);
    }

    void reset(){

    }

    int get_button_state(){
        return digitalRead(this->button_pin);
    }
};

#endif // __BUTTON_MODULE_H
