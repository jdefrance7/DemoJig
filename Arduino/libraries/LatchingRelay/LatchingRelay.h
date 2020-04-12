#ifndef LATCHING_RELAY_H
#define LATCHING_RELAY_H

// Provides Latching Relay object array (relays[]) and init function.

#define NUMBER_OF_RELAYS 4

#define RELAY_1_LATCH_PIN     -1
#define RELAY_1_UNLATCH_PIN   -1

#define RELAY_2_LATCH_PIN     -1
#define RELAY_2_UNLATCH_PIN   -1

#define RELAY_3_LATCH_PIN     -1
#define RELAY_3_UNLATCH_PIN   -1

#define RELAY_4_LATCH_PIN     -1
#define RELAY_4_UNLATCH_PIN   -1

// Latching Relay Class
class LatchingRelay()
{
public:
  LatchingRelay();
  LatchingRelay(int latch, int unlatch);
  void setLatch(int latch);
  void setUnlatch(int unlatch);
  void setPins(int latch, int unlatch);
  bool latched();
  void latch();
  void unlatch();
  void toggle();
private:
  bool _latched;
  int _latch;
  int _unlatch;
};

// Latching Relay Object(s)
extern LatchingRelay relays[NUMBER_OF_RELAYS];

// Initialization function
int initRelays();

#endif
