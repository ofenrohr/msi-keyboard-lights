cmake_minimum_required(VERSION 3.9)
project(msi_keyboard_lights)

set(CMAKE_CXX_STANDARD 11)

find_package(PkgConfig)

#pkg_check_modules(HIDAPI REQUIRED hidapi-hidraw)
pkg_check_modules(HIDAPI REQUIRED hidapi-libusb)

message(STATUS "hidapi libs: " ${HIDAPI_LIBRARIES})
message(STATUS "hidapi includes: " ${HIDAPI_INCLUDE_DIRS})

include_directories(${HIDAPI_INCLUDE_DIRS})

set(SOURCE_FILES src/main.cpp src/MSIKeyboard.cpp src/MSIKeyboard.h)

add_executable(msi-keyboard-lights ${SOURCE_FILES})
target_link_libraries(msi-keyboard-lights ${HIDAPI_LIBRARIES})

INSTALL(TARGETS msi-keyboard-lights RUNTIME DESTINATION /usr/bin)
INSTALL(FILES doc/90-msi-keyboard.rules DESTINATION /etc/udev/rules.d)