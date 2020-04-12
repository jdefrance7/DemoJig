// Arduino Library
#include <Arduino.h>

// Custom Libraries
#include <INA219.h>
#include <OLED.h>
#include <LatchingRelay.h>
#include <Serial.h>
#include <LED.h>

// Global state variable
typedef int STATE
#define STATE_INIT      0
#define STATE_IDLE      1
#define STATE_MANUAL    2
#define STATE_RUN       3
STATE state = STATE_INIT;

// State function declarations
STATE initialization();
STATE idle();
STATE run();

// Delay between display updates in idle mode
#define IDLE_DELAY 600

// Value sent by Raspberry Pi to enter run mode
#define RUN 'A'

void setup()
{
  // pass
}

void loop()
{
  switch(state)
  {
    case STATE_INIT:
      state = initialization();
      break;
    case STATE_IDLE:
      state = idle();
      break;
    case STATE_RUN:
      state = run();
      break;
    default:
      state = initialization();
      break;
  }
}

STATE initialization()
{
  if(initSerial())
  {
    led.toggle(ERROR_TOGGLE_RATE);
    return STATE_INIT;
  }

  if(initRelays())
  {
    led.toggle(ERROR_TOGGLE_RATE);
    return STATE_INIT;
  }

  if(initINA219())
  {
    led.toggle(ERROR_TOGGLE_RATE);
    return STATE_INIT;
  }

  if(initOLED())
  {
    led.toggle(ERROR_TOGGLE_RATE);
    return STATE_INIT;
  }
}

STATE idle()
{
  int sensor = 0;
  long idle_time = millis();

  while(1)
  {
    if(millis() - idle_time > IDLE_DELAY)
    {
      oled.clearDisplay();
      oled.print("Sensor: ");   oled.println(sensor);
      oled.print("Voltage: ");  oled.print(ina219[sensor].getBusVoltage_V()); oled.println(" V");
      oled.print("Current: ");  oled.print(ina219[sensor].getCurrent_mA());   oled.println(" mA");
      oled.print("Power: ");    oled.print(ina219[sensor].getPower_mW());     oled.println(" mW");
      oled.display();

      for(int n = 0; n < NUMBER_OF_SENSORS; n++)
      {
        Serial.print("\nSensor: ");   Serial.println(n);
        Serial.print("  Voltage: ");  Serial.print(ina219[n].getBusVoltage_V());  Serial.println(" V");
        Serial.print("  Current: ");  Serial.print(ina219[n].getCurrent_mA());    Serial.println(" mA");
        Serial.print("  Power: ");    Serial.print(ina219[n].getPower_mW());      Serial.println(" mW");
      }

      idle_time = millis();
    }

    if(!digitalRead(BUTTON_A))
    {
      sensor++;
      sensor %= NUMBER_OF_SENSORS;
    }
    else if(!digitalRead(BUTTON_C))
    {
      sensor = sensor + (NUMBER_OF_SENSORS-1);
      sensor %= NUMBER_OF_SENSORS;
    }
    else if(!digitalRead(BUTTON_B))
    {
      relays[n].toggle();
    }

    if(Serial.available())
    {
      if(Serial.read() == RUN_TOKEN)
      {
        return STATE_RUN;
      }
    }
  }

  return STATE_IDLE;
}

STATE run()
{
  // TODO: develop a test algorithm
}
