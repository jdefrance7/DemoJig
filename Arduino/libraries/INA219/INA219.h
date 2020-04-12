#ifndef INA219_H
#define INA219_H

// Provides INA219 object array (ina219[]) and init function.

#include <Adafruit_INA219.h>

#define NUMBER_OF_SENSORS 4

#define INA219_ADDRESS_1     0x40
#define INA219_ADDRESS_2     0x41
#define INA219_ADDRESS_3     0x44
#define INA219_ADDRESS_4     0x45

// INA219 Object(s)
extern Adafruit_INA219 ina219[NUMBER_OF_SENSORS];

// Initialization function
int initINA219();

#endif
