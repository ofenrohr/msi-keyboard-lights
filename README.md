# MSI keyboard backlight

Program to change backlight colors of keyboard in MSI laptops. It is based on the nodeJs package _msi-keyboard_.

## Install

To use this program without root privileges, you can add a udev rule. It allows your user to access the backlight device and creates the symlink `/dev/msikeyboard`.

Installation will put the following rule in `/etc/udev/rules.d/90-msi-keyboard.rules`:

```
ATTRS{idVendor}=="1770", ATTRS{idProduct}=="ff00", MODE="0666", SYMLINK+="msikeyboard"
```

Compile and install:
```
mkdir build; cd build
cmake ..
make
sudo make install
```

Reload the udev rules:
```
sudo udevadm control --reload-rules
sudo udevadm trigger
```

Test the program:
```
msi-keyboard-lights ff0000 00ff00 0000ff
```

## Usage

```
  msi-keyboard-lights RRGGBB [RRGGBB RRGGBB]
```

Either set the same color for all regions or set each region individually
Color format is red, green, blue written in two digit hex format