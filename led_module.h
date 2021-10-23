#if !defined(__LED_MODULE)
#define __LED_MODULE

#include "base_module.h"

class LEDModule: public BaseModule{

    int led_pin;

    unsigned long last_inner_update_time;
    unsigned long on_time;
    unsigned long off_time;

public:
    
    LEDModule(int led_pin){
        this->led_pin = led_pin;
        this->set_last_inner_update_time(millis());
    }

    bool is_led_on(){
        if(digitalRead(this->led_pin)){
            return true;
        }
        return false;
    }

    void set_last_inner_update_time(unsigned long time){
        this->last_inner_update_time = time;
    }

    void set_on_off_time(unsigned long on_time, unsigned long off_time){
        this->set_on_time(on_time);
        this->set_off_time(off_time);
    }

    void set_off_time(unsigned long off_time){
        this->off_time = off_time;
    }
    
    void set_on_time(unsigned long on_time){
        this->on_time = on_time;
    }

    void turn_led_on(){
        digitalWrite(this->led_pin, HIGH);
    }

    void turn_led_off(int led_id){
        digitalWrite(this->led_pin, LOW);
    }

    void init_pins(){
        pinMode(this->led_pin, OUTPUT);
    }

    void reset(){
        this->set_last_inner_update_time(0);
    }

    void toggle_led(){
        if(is_led_on(this->led_pin) == true){
            this->led_off();
        }else{
            this->led_on();
        }
    }

    unsigned short toggle_dif(unsigned long current_millis, unsigned long on_time, unsigned long off_time){
        bool led_state = is_led_on();

        unsigned long update_time;
        if(!led_state){
            update_time = off_time;
        }else{
            update_time = on_time;
        }

        if(current_millis - this->last_inner_update_time >= update_time){
            this->toggle_led();
            this->last_inner_update_time = current_millis;
            return true;
        }else{
            return false;
        }
    }
};

#endif // __LED_MODULE
