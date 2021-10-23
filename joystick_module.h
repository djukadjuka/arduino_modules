#if !defined(__JOYSTICK_MODULE_H)
#define __JOYSTICK_MODULE_H

#include "base_module.h"

#define JOYSTICK_VAL_MAX        (1023)
#define JOYSTICK_VAL_MIN        (0)
#define JOYSTICK_VAL_MID        (507)
#define JOYSTICK_VAL_TOLERANCE  (3)

#define JOYSTICK_POS_MID    (0)
#define JOYSTICK_POS_UP     (1)
#define JOYSTICK_POS_DOWN   (3)
#define JOYSTICK_POS_LEFT   (2)
#define JOYSTICK_POS_RIGHT  (4)

class JoystickModule{

    uint8_t pin_x, pin_y;

    // Use this if the joystick needs to be installed upside down
    bool invert_controls;

    int get_x(){
        return analogRead(pin_x);
    };

    int get_y(){
        return analogRead(pin_y);
    };

    uint8_t get_x_direction(){
        int x = this->get_x();
        if(x <= JOYSTICK_VAL_MID + JOYSTICK_VAL_TOLERANCE && x >= JOYSTICK_VAL_MID - JOYSTICK_VAL_TOLERANCE){
            return JOYSTICK_POS_MID;
        }
        if(x > JOYSTICK_VAL_MID + JOYSTICK_VAL_TOLERANCE){
            return JOYSTICK_POS_RIGHT;
        }
        return JOYSTICK_POS_LEFT;
    }

    uint8_t get_y_direction(){
        int y = this->get_y();
        if(y <= JOYSTICK_VAL_MID + JOYSTICK_VAL_TOLERANCE && y >= JOYSTICK_VAL_MID - JOYSTICK_VAL_TOLERANCE){
            return JOYSTICK_POS_MID;
        }
        if(y > JOYSTICK_VAL_MID + JOYSTICK_VAL_TOLERANCE){
            return JOYSTICK_POS_DOWN;
        }
        return JOYSTICK_POS_UP;
    }

public:

    bool up(){
        if(this->invert_controls){
            return this->get_y_direction() == JOYSTICK_POS_DOWN;
        }
        return this->get_y_direction() == JOYSTICK_POS_UP;
    }

    bool down(){
        if(this->invert_controls){
            return this->get_y_direction() == JOYSTICK_POS_UP;
        }
        return this->get_y_direction() == JOYSTICK_POS_DOWN;
    }

    bool left(){
        if(this->invert_controls){
            return this->get_x_direction() == JOYSTICK_POS_RIGHT;
        }
        return this->get_x_direction() == JOYSTICK_POS_LEFT;
    }

    bool right(){
        if(this->invert_controls){
            return this->get_x_direction() == JOYSTICK_POS_LEFT;
        }
        return this->get_x_direction() == JOYSTICK_POS_RIGHT;
    }

    bool mid_x(){
        return this->get_x_direction() == JOYSTICK_POS_MID;
    }

    bool mid_y(){
        return this->get_y_direction() == JOYSTICK_POS_MID;
    }

    bool mid(){
        return mid_x() && mid_y();
    }

    JoystickModule(uint8_t pin_x, uint8_t pin_y, bool invert_controls=false){
        this->pin_x = pin_x;
        this->pin_y = pin_y;
        this->invert_controls = invert_controls;
    };

    void init_pins(){

    };

    void reset(){

    };

};

#endif // __JOYSTICK_MODULE_H
