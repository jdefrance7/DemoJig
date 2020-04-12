#include "INA219.h"

// INA219 Object(s)
Adafruit_INA219 ina219[NUMBER_OF_SENSORS];

// Initialization function
int initINA219()
{
  if(NUMBER_OF_SENSORS > 0)
  {
    ina219[0] = Adafruit_INA219(INA219_ADDRESS_1);
    ina219[0].begin();
  }
  if(NUMBER_OF_SENSORS > 1)
  {
    ina219[1] = Adafruit_INA219(INA219_ADDRESS_2);
    ina219[1].begin();
  }
  if(NUMBER_OF_SENSORS > 2)
  {
    ina219[2] = Adafruit_INA219(INA219_ADDRESS_3);
    ina219[2].begin();
  }
  if(NUMBER_OF_SENSORS > 3)
  {
    ina219[3] = Adafruit_INA219(INA219_ADDRESS_4);
    ina219[3].begin();
  }
}
