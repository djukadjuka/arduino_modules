#if !defined(__TFT_OLED_MODULE_H)
#define __TFT_OLED_MODULE_H

#include "base_module.h"
#include "tamara_slika.h"

#include <LCDWIKI_GUI.h> // Core graphics library
#include <LCDWIKI_SPI.h> // Hardware-specific library

// Example for pins
// #define MODEL SSD1283A
// #define CS   10
// #define CD   9
// #define SDA  A2   //if you use the hardware spi,this pin is no need to set
// #define SCK  A1   //if you use the hardware spi,this pin is no need to set
// #define RST  8
// #define LED  A3

class TFTOLEDModule : BaseModule{

    int model;
    int cs, cd, sda, sck, rst, led;
    LCDWIKI_SPI *screen = NULL;

public:
    TFTOLEDModule(int model, int cs, int cd, int sda, int sck, int rst, int led){
        this->model = model;
        this->cs = cs;
        this->cd = cd;
        this->sda = sda;
        this->sck = sck;
        this->rst = rst;
        this->led = led;
    };

    virtual void init_pins(){
        this->screen = new LCDWIKI_SPI(this->model, this->cs, this->cd, this->rst, this->led);

        this->screen->Init_LCD();
        this->screen->Fill_Screen(0x0000);
        this->screen->Fill_Screen(0xFFFF);
    }

    virtual void reset(){
        this->clear_screen();
    }

    ///////////////////////
    // SHORTHAND FUNCTIONS
    ///////////////////////
    void clear_screen(){
        // Clears the screen and fills it with black color
        this->fill_screen(0, 0, 0);
    }

    bool print_string(String str, uint16_t x, uint16_t y){
        if(x >= this->get_width() || x < 0){
            return false;
        }
        if(y >= this->get_height() || y < 0){
            return false;
        }
        this->screen->Print_String(str, x, y);
        return true;
    }

    void draw_image(){
        this->screen->Set_Addr_Window(0, 0, 58, 79);
        this->screen->Push_Any_Color(gImage_tamara, sizeof(gImage_tamara) / 2, 1, 1);
    }

    //////////////////////
    // DRAWING PRIMITIVES
    //////////////////////
    
    // Sets the color for the next drawing operations
    void set_draw_color(uint8_t r, uint8_t g, uint8_t b){
        this->screen->Set_Draw_color(r, g, b);
    }

    //
    // RECTANGLE
    //

    // Draws rectangle on screen with (x1, y1) being top left point and (x2, y2) being bottom right point
    void draw_rectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2){
        this->screen->Draw_Rectangle(x1, y1, x2, y2);
    }
    // Draws rectangle on screen with (x1, y1) being top left point and (x2, y2) being bottom right point using the color (r, g, b)
    void draw_rectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t r, uint8_t g, uint8_t b){
        this->set_draw_color(r, g, b);
        this->draw_rectangle(x1, y1, x2, y2);
    }
    // Fills rectangle on screen with (x1, y1) being top left point and (x2, y2) being bottom right point
    void fill_rectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2){
        this->screen->Fill_Rectangle(x1, y1, x2, y2);
    }
    // Fills rectangle on screen with (x1, y1) being top left point and (x2, y2) being bottom right point using the color (r, g, b)
    void fill_rectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t r, uint8_t g, uint8_t b){
        this->set_draw_color(r, g, b);
        this->fill_rectangle(x1, y1, x2, y2);
    }

    //
    // CIRCLE
    //

    // Draws circle on (x, y) with radius r
    void draw_circle(uint16_t x, uint16_t y, uint16_t rd){
        this->screen->Draw_Circle(x, y, rd);
    }
    // Draws circle on (x, y) with radius r and color (r, g, b)
    void draw_circle(uint16_t x, uint16_t y, uint16_t rd, uint8_t r, uint8_t g, uint8_t b){
        this->set_draw_color(r, g, b);
        this->draw_circle(x, y, rd);
    }
    // Fills circle on (x, y) with radius r
    void fill_circle(uint16_t x, uint16_t y, uint16_t rd){
        this->screen->Fill_Circle(x, y, rd);
    }
    // Fills circle on (x, y) with radius r and color (r, g, b)
    void fill_circle(uint16_t x, uint16_t y, uint16_t rd, uint8_t r, uint8_t g, uint8_t b){
        this->set_draw_color(r, g, b);
        this->fill_circle(x, y, rd);
    }

    //
    // TRIANGLE
    //

    // Draw triangle between three points (x1, y1) - (x2, y2) - (x3, y3)
    void draw_triangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3){
        this->screen->Draw_Triangle(x1, y1, x2, y2, x3, y3);
    }
    // Draw triangle between three points (x1, y1) - (x2, y2) - (x3, y3) and color (r, g, b)
    void draw_triangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint8_t r, uint8_t g, uint8_t b){
        this->set_draw_color(r, g, b);
        this->draw_triangle(x1, y1, x2, y2, x3, y3);
    }
    // Fill triangle between three points (x1, y1) - (x2, y2) - (x3, y3)
    void fill_triangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3){
        this->screen->Fill_Triangle(x1, y1, x2, y2, x3, y3);
    }
    // Fill triangle between three points (x1, y1) - (x2, y2) - (x3, y3) and color (r, g, b)
    void fill_triangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint8_t r, uint8_t g, uint8_t b){
        this->set_draw_color(r, g, b);
        this->fill_triangle(x1, y1, x2, y2, x3, y3);
    }

    // Draws a single pixel on (x, y)
    void draw_pixel(uint16_t x, uint16_t y){
        this->screen->Draw_Pixel(x, y);
    }
    // Draws a single pixel on (x1, y1) using color (r, g, b)
    void draw_pixel(uint16_t x, uint16_t y, uint8_t r, uint8_t g, uint8_t b){
        this->set_draw_color(r, g, b);
        this->draw_pixel(x, y);
    }
    
    // LINE

    // Draws a line on the screen from (x1, y1) to (x2, y2)
    void draw_line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2){
        this->screen->Draw_Line(x1, y1, x2, y2);
    }
    // Draws a line on the screen from (x1, y1) to (x2, y2) using the color (r, g, b)
    void draw_line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t r, uint8_t g, uint8_t b){
        this->set_draw_color(r, g, b);
        this->draw_line(x1, y1, x2, y2);
    }
    // Draws a line on the screen from (x1, y1) to (x2, y2)
    void draw_line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t thickness){
        
        this->screen->Draw_Line(x1, y1, x2, y2);
    }
    // Draws a line on the screen from (x1, y1) to (x2, y2) using the color (r, g, b)
    void draw_line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t r, uint8_t g, uint8_t b, uint8_t thickness){
        this->set_draw_color(r, g, b);
        this->draw_line(x1, y1, x2, y2);
    }
    // Draws pixels randomly dispersed along the line (x1, y1), (x2, y2)
    void draw_dispersed_pixels_along_line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t dispersion_max){
        uint16_t number_of_points = abs(int16_t(x1) - int16_t(x2));
        if(abs(y1 - y2) > number_of_points){
            number_of_points = abs(int16_t(y1) - int16_t(y2));
        }
        uint16_t startx = x1, endx = x2, starty = y1, endy = y2;
        if(x1 > x2){
            startx = x2; 
            endx = x1;
        }
        if(y1 > y2){
            starty = y2;
            endy = y1;
        }

        for(uint16_t step = 0;  step < number_of_points;    step++){
            float t = float(step) / float(number_of_points);
            uint16_t x_lerp = lerp(startx, endx, t);
            uint16_t y_lerp = lerp(starty, endy, t);

            // Add disperion to x,y, max points is dispersion^2
            uint16_t max_points = random(dispersion_max * dispersion_max);
            for(uint16_t pt = 0;    pt < max_points;    pt++){
                int16_t disper = random(dispersion_max);
                
                // Coinflip to add or subtract for x
                if(random(2) == 0){
                    disper *= -1;
                }
                x_lerp += disper;

                disper = abs(disper);
                // Coinflip to add or subtract for y
                if(random(2) == 0){
                    disper *= -1;
                }
                y_lerp += disper;
                this->draw_pixel(x_lerp, y_lerp, 255, 255, 255);
            }
        }

    }
    // Draws pixels randomly dispersed along the line (x1, y1), (x2, y2) with color (r, g, b)
    void draw_dispersed_pixels_along_line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t r, uint8_t g, uint8_t b, uint16_t dispersion_max){
        this->set_draw_color(r, g, b);
        this->draw_dispersed_pixels_along_line(x1, y1, x2, y2, dispersion_max);
    }

    float lerp(uint16_t start, uint16_t end, float t){
        return float(start + t * (end - start));
    }

    /////////////////////////
    // UTILITIES AND NATIVES
    /////////////////////////
    

    void set_text_color(uint8_t r, uint8_t g, uint8_t b){
        this->screen->Set_Text_colour(r, g, b);
    }
    void set_text_background_color(uint8_t r, uint8_t g, uint8_t b){
        this->screen->Set_Text_Back_colour(r, g, b);
    }

    void fill_screen(uint8_t r, uint8_t g, uint8_t b){
        // Fills the screen with any RGB color
        this->screen->Fill_Screen(r, g, b);
    }

    uint16_t get_width(){
        // Returns width of display in pixels
        return this->screen->Get_Width();
    }
    uint16_t get_height(){
        // Returns height of display in pixels
        return this->screen->Get_Height();
    }

};

#endif // __TFT_OLED_MODULE_H
