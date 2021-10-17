#if !defined(__LED_MODULE)
#define __LED_MODULE

#include "base_module.h"

#define LED_PIN (3)

class LEDModule: public BaseModule{

    unsigned long last_inner_update_time;
    unsigned long on_time;
    unsigned long off_time;

public:
    
    LEDModule(){
        this->set_last_inner_update_time(millis());
    }

    bool is_led_on(int led_id){
        if(digitalRead(led_id)){
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

    void led_on(int led_id){
        digitalWrite(led_id, HIGH);
    }

    void led_off(int led_id){
        digitalWrite(led_id, LOW);
    }

    void init_pins(){
        pinMode(LED_PIN, OUTPUT);
    }

    void reset(){
        this->set_last_inner_update_time(0);
    }

    void toggle_led(int led_id){
        if(is_led_on(led_id) == true){
            this->led_off(led_id);
        }else{
            this->led_on(led_id);
        }
    }

    void off_all(){
        this->led_off(LED_PIN);
    }

    void on_all(){
        this->led_on(LED_PIN);
    }

    unsigned short toggle_dif(unsigned long current_millis, unsigned long on_time, unsigned long off_time, int led_id){
        bool led_state = is_led_on(led_id);

        unsigned long update_time;
        if(!led_state){
            update_time = off_time;
        }else{
            update_time = on_time;
        }

        if(current_millis - this->last_inner_update_time >= update_time){
            this->toggle_led(led_id);
            this->last_inner_update_time = current_millis;
            return true;
        }else{
            return false;
        }
    }
};

#endif // __LED_MODULE
