cmake_minimum_required(VERSION 3.9)
project(msi_keyboard_lights)

set(CMAKE_CXX_STANDARD 11)

find_package(PkgConfig)
#pkg_check_modules(LIBUSB REQUIRED libusb-1.0)

#pkg_check_modules(LIBUSB REQUIRED hidapi-hidraw)
pkg_check_modules(LIBUSB REQUIRED hidapi-libusb)

message(STATUS "libusb libs: " ${LIBUSB_LIBRARIES})
message(STATUS "libusb includes: " ${LIBUSB_INCLUDE_DIRS})

include_directories(${LIBUSB_INCLUDE_DIRS})

set(SOURCE_FILES src/main.cpp src/MSIKeyboard.cpp src/MSIKeyboard.h)

add_executable(msi-keyboard-lights ${SOURCE_FILES})
target_link_libraries(msi-keyboard-lights ${LIBUSB_LIBRARIES})

INSTALL(TARGETS msi-keyboard-lights RUNTIME DESTINATION /usr/bin)