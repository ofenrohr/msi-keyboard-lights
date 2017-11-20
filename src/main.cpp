#include <cstdio>
#include <string>
#include "MSIKeyboard.h"

void usage() {
    printf("Usage:\n\n");
    printf("  msi-keyboard-lights RRGGBB\n");
    printf("  msi-keyboard-lights RRGGBB RRGGBB RRGGBB\n\n");
    printf("Either set the same color for all regions or set each region individually\n");
    printf("Color format is red, green, blue written in hex format\n");
}

int main(int argc, char **argv) {
    if (argc != 2 && argc != 4) {
        usage();
        return 2;
    }

    unsigned char left_red = 255;
    unsigned char left_green = 0;
    unsigned char left_blue = 0;

    unsigned char middle_red = 0;
    unsigned char middle_green = 255;
    unsigned char middle_blue = 0;

    unsigned char right_red = 0;
    unsigned char right_green = 0;
    unsigned char right_blue = 255;

    if (argc == 2) {
        std::string colorStr(argv[1]);
        if (colorStr.length() != 6) {
            printf("Error: invalid color\n\n");
            usage();
            return 2;
        }

        // TODO: parse color
    }


    MSIKeyboard keyboard;

    if (!keyboard.initKeyboard()) {
        return 1;
    }

    if (!keyboard.setColor(MSIKeyboard::RegionLeft, left_red, left_green, left_blue)) {
        return 1;
    }
    if (!keyboard.setColor(MSIKeyboard::RegionMiddle, middle_red, middle_green, middle_blue)) {
        return 1;
    }
    if (!keyboard.setColor(MSIKeyboard::RegionRight, right_red, right_green, right_blue)) {
        return 1;
    }

    return 0;
}