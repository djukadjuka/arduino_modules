#if !defined(__BUTTON_MODULE_H)
#define __BUTTON_MODULE_H

#include "base_module.h"

#define BUTTON_PIN (3)
#define BUTTON_STATE_PRESSED (1)

class ButtonModule: public BaseModule{

public:
    void init_pins(){
        pinMode(BUTTON_PIN, INPUT);
    }

    void reset(){

    }

    int get_button_state(){
        return digitalRead(BUTTON_PIN);
    }
};

#endif // __BUTTON_MODULE_H
