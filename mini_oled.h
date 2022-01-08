#if !defined(__MINI_OLED_MODULE)
#define __MINI_OLED_MODULE

#include "base_module.h"

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)

class MiniOLEDModule: public BaseModule{

    Adafruit_SSD1306 display;

public:
    
    MiniOLEDModule(){

    }

    virtual void init_pins(){
        this->display = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
        if(!this->display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
            Serial.println(F("SSD1306 allocation failed"));
        }
        this->display.setTextColor(WHITE);
        this->write_text(0, 0, 1, "Example text.");
    }

    virtual void reset(){

    }

    void clear_screen(){
        this->display.clearDisplay();
        this->display.display();
    }

    void write_text(uint8_t x, uint8_t y, uint8_t size, String text){
        // Size supports [1, 8]
        // x = [0, SCREEN_WIDTH]
        // y = [0, SCREEN_HEIGHT]
        if(x >= SCREEN_WIDTH){
            x = SCREEN_WIDTH - 1;
        }
        if(x < 0){
            x = 0;
        }
        if(y >= SCREEN_HEIGHT){
            y = SCREEN_HEIGHT - 1;
        }
        if(y < 0){
            y = 0;
        }
        this->display.clearDisplay();
        this->display.setTextSize(size);
        this->display.setCursor(x, y);
        this->display.println(text);
        this->display.display();
    }

};

#endif // __MINI_OLED_MODULE
