#if !defined(__SERVO_MODULE_H)
#define __SERVO_MODULE_H

// TODO: NEEDS TO INCLUDE SERVO.H FROM LIBRARY MANAGER
// sketch -> include libraries -> manage libraries -> servo

#include <Servo.h>
#include "base_module.h"

class ServoModule{

    Servo servo;
    uint8_t servo_pin;

    // From 0 to 180
    uint8_t servo_position;

public:
    ServoModule(uint8_t servo_pin){
        this->servo_pin = servo_pin;
    }

    void init_pins(){
        this->servo.attach(this->servo_pin);
    }

    void reset(){
        // TODO: Add custom reset here
    }

    void move_servo_to_pos(uint8_t new_servo_position){
        this->servo.write(new_servo_position);
        this->servo_position = new_servo_position;
    }

    uint8_t get_servo_position(){
        return this->servo_position;
    }
};

#endif // __SERVO_MODULE_H

