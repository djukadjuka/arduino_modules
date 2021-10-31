#if !defined(__MICRO_SD_MODULE_H)
#define __MICRO_SD_MODULE_H

#include <SPI.h>
#include <SD.h>

#include "base_module.h"

////////////////////////////////////////////////////
// FILENAMES ARE FREAKING LIMITED TO 8 CHARACTERS //
////////////////////////////////////////////////////

class MicroSDModule: BaseModule{

    File file;
    uint8_t cpin;

public:
    MicroSDModule(uint8_t cpin){
        this->cpin = cpin;
    }

    void init_pins(){
        if(!SD.begin(this->cpin)){
            Serial.print("Could not start SD card reader on pin ");
            Serial.println(this->cpin);
        }
    }

    void reset(){
        // Close file and destroy pointer
        if(this->file){
            this->file.close();
        }
    }

    String read_from_file(String filepath){
        // Reads all data from file and returns read data from filepath.
        // Returns nullptr if file not found
        if(this->file){
            this->file.close();
        }

        this->file = SD.open(filepath, FILE_READ);

        String return_data = "";
        while(this->file.available()){
            return_data += char(this->file.read());
        }

        this->file.close();

        return return_data;
    }

    bool write_to_file(String filepath, String contents){
        // Writes all data to file
        // Returns false if write not possible
        if(this->file){
            this->file.close();
        }

        if(SD.exists(filepath)){
            SD.remove(filepath);
        }

        this->file = SD.open(filepath, FILE_WRITE);
        if(!this->file){
            return false;
        }

        this->file.println(contents);
        this->file.close();

        return true;
    }

    bool append_data_to_file(String filepath, String contents){
        // Reads all data from file, and appends new content and writes to file
        // Returns false if write not possible
        if(this->file){
            this->file.close();
        }

        this->file = SD.open(filepath, FILE_WRITE);
        this->file.print(contents);
        this->file.close();

        return true;
    }

};

#endif // __MICRO_SD_MODULE_H
