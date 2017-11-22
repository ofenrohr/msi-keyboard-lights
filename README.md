# MSI keyboard backlight

`msi-keyboard-lights` is a lightweight command line utility to change the backlight colors of a Steelseries keyboard in MSI laptops. It 
is based on [msi-keyboard](https://github.com/stevelacy/msi-keyboard) written by Steve Lacy.

To use this tool, you need a Steelseries keyboard. Output of lsusb on my machine:
```
Bus 002 Device 003: ID 1770:ff00
[...]
```

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

Either set the same color for all regions or set each region individually.
Color format is red, green, blue written in two digit hex format