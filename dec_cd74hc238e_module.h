#ifndef __DEC_CD74HC238E_MODULE_H
#define __DEC_CD74HC238E_MODULE_H

#include "base_module.h"

class DecCd74Hc238eModule: public BaseModule{
    uint8_t A0_pin;
    uint8_t A1_pin;
    uint8_t A2_pin;
    uint8_t EN_pin;

public:
    DecCd74Hc238eModule(uint8_t A0_pin, uint8_t A1_pin, uint8_t A2_pin, uint8_t EN_pin){
        this->A0_pin = A0_pin;
        this->A1_pin = A1_pin;
        this->A2_pin = A2_pin;
        this->EN_pin = EN_pin;
    };

    virtual void init_pins(){
        pinMode(this->A0_pin, OUTPUT);
        pinMode(this->A1_pin, OUTPUT);
        pinMode(this->A2_pin, OUTPUT);
        pinMode(this->EN_pin, OUTPUT);
    }

    virtual void reset(){
        digitalWrite(this->A0_pin, LOW);
        digitalWrite(this->A0_pin, LOW);
        digitalWrite(this->A0_pin, LOW);
        digitalWrite(this->EN_pin, LOW);
    }

    bool set_enabled(bool enabled){
        if(enabled){
            digitalWrite(this->EN_pin, HIGH); 
        }else{
            digitalWrite(this->EN_pin, LOW);
        }
    }

    void set_output_code(uint8_t output_code){
        /// Output code should be [0, 7]
        // Reset all pin values
        digitalWrite(this->A0_pin, LOW);
        digitalWrite(this->A1_pin, LOW);
        digitalWrite(this->A2_pin, LOW);
        
        Serial.print(">> ");
        Serial.print(output_code); Serial.print(" & "); Serial.print(2); Serial.print(" = "); Serial.print(output_code & 2);
        Serial.println(" <<");

        uint8_t a0out = LOW;
        uint8_t a1out = LOW;
        uint8_t a2out = LOW;

        if(output_code & 4){
            a2out = HIGH;
            Serial.print("1");
        }
        else{
          Serial.print("0");
        }

        if(output_code & 2){
            a1out = HIGH;
            Serial.print("1");
        }
        else{
          Serial.print("0");
        }

        if(output_code & 1){
            a0out = HIGH;
            Serial.print("1");
        }
        else{
          Serial.print("0");
        }
        
        digitalWrite(this->A0_pin, a0out);
        digitalWrite(this->A1_pin, a1out);
        digitalWrite(this->A2_pin, a2out);

        Serial.println();
    }

};

#endif // __DEC_CD74HC238E_MODULE_H
