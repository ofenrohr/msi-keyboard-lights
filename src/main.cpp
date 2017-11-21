#include <cstdio>
#include <string>
#include <sstream>
#include "MSIKeyboard.h"

void usage() {
    printf("Usage:\n\n");
    printf("  msi-keyboard-lights RRGGBB [RRGGBB RRGGBB]\n\n");
    printf("Either set the same color for all regions or set each region individually\n");
    printf("Color format is red, green, blue written in two digit hex format\n");
}

bool validHex(const std::string &hex) {
    if (hex.length() != 2) {
        return false;
    }
    return hex.find_first_not_of("abcdefABCDEF0123456789") == -1;
}

unsigned char parseHex(const std::string &hex) {
    return (unsigned char) std::stoul(hex, nullptr, 16);
}

bool parseColorString(const std::string &colorStr, MSIKeyboard::Color *color) {
    if (colorStr.length() != 6) {
        printf("Error: invalid color\n\n");
        usage();
        return false;
    }

    std::string r,g,b;
    r = colorStr.substr(0,2);
    g = colorStr.substr(2,2);
    b = colorStr.substr(4,2);
    if (!validHex(r) || !validHex(g) || !validHex(b)) {
        printf("Error: invalid color\n\n");
        usage();
        return false;
    }

    printf("rgb: %s %s %s\n", r.c_str(),g.c_str(),b.c_str());

    color->red = parseHex(r);
    color->green = parseHex(g);
    color->blue = parseHex(b);


    return true;
}

int main(int argc, char **argv) {
    if (argc != 2 && argc != 4) {
        usage();
        return 2;
    }

    MSIKeyboard::Color leftColor { 255, 0, 0 };
    MSIKeyboard::Color middleColor { 0, 255, 0 };
    MSIKeyboard::Color rightColor { 0, 0, 255 };

    if (argc == 2) {
        std::string colorStr(argv[1]);

        MSIKeyboard::Color color{};
        if (!parseColorString(colorStr, &color)) {
            return 3;
        }

        leftColor = middleColor = rightColor = color;
        printf("color: %x %x %x\n", color.red, color.green, color.blue);
    }

    if (argc == 4) {
        std::string leftColorStr(argv[1]);
        std::string middleColorStr(argv[2]);
        std::string rightColorStr(argv[3]);

        if (!parseColorString(leftColorStr, &leftColor)) {
            return 4;
        }
        if (!parseColorString(middleColorStr, &middleColor)) {
            return 5;
        }
        if (!parseColorString(rightColorStr, &rightColor)) {
            return 6;
        }

        printf("left color: %x %x %x\n", leftColor.red, leftColor.green, leftColor.blue);
        printf("middle color: %x %x %x\n", middleColor.red, middleColor.green, middleColor.blue);
        printf("right color: %x %x %x\n", rightColor.red, rightColor.green, rightColor.blue);
    }


    MSIKeyboard keyboard;

    if (!keyboard.initKeyboard()) {
        return 1;
    }

    if (!keyboard.setColor(MSIKeyboard::RegionLeft, leftColor)) {
        return 7;
    }
    if (!keyboard.setColor(MSIKeyboard::RegionMiddle, middleColor)) {
        return 8;
    }
    if (!keyboard.setColor(MSIKeyboard::RegionRight, rightColor)) {
        return 9;
    }

    return 0;
}