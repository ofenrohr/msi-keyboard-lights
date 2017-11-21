# MSI keyboard backlight

Program to change backlight colors of keyboard in MSI laptops. It is based on the nodeJs package _msi-keyboard_.

## Install

To use this program without root privileges, you can add a udev rule. It allows your user to access the backlight device, adds the device to the group `wheel` and creates `/dev/msikeyboard`.

Put the following rule in `/etc/udev/rules.d/90-msi-keyboard.rules`

```
ATTR{idVendor}=="1771", ATTR{idProduct}=="ff00", GROUP="wheel", MODE="0777", SYMLINK+="msikeyboard"
```

## Usage

```
  msi-keyboard-lights RRGGBB [RRGGBB RRGGBB]
```

Either set the same color for all regions or set each region individually
Color format is red, green, blue written in two digit hex format