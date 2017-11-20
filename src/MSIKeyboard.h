//
// Created by ofenrohr on 20.11.17.
//

#ifndef MSI_KEYBOARD_LIGHTS_MSIKEYBOARD_H
#define MSI_KEYBOARD_LIGHTS_MSIKEYBOARD_H

#include <hidapi.h>

class MSIKeyboard {
public:
    enum Region {
        RegionLeft = 1,
        RegionMiddle = 2,
        RegionRight = 3
    };

    MSIKeyboard();
    ~MSIKeyboard();

    bool initKeyboard();
    bool setColor(Region region, unsigned char red, unsigned  char green, unsigned char blue);

private:
    int MAX_STR = 255;
    hid_device *handle;
};


#endif //MSI_KEYBOARD_LIGHTS_MSIKEYBOARD_H
