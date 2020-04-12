#include "LatchingRelay.h"

// Latching Relay Object(s)
LatchingRelay relays[NUMBER_OF_RELAYS];

LatchingRelay::LatchingRelay()
{
  _latched = false;
  _latch = -1;
  _unlatch = -1;
}

LatchingRelay::LatchingRelay(int latch, int unlatch)
{
  _latch = latch;
  _unlatch = unlatch;
  unlatch();
}

void LatchingRelay::setLatch(int latch)
{
  _latch = latch;
}

void LatchingRelay::setUnlatch(int unlatch)
{
  _unlatch = unlatch;
}

void LatchingRelay::setPins(int latch, int unlatch)
{
  _latch = latch;
  _unlatch = unlatch;
}

bool LatchingRelay::latched()
{
  return _latched;
}

void LatchingRelay::latch()
{
  if(_latch == -1)
  {
    return;
  }

  digitalWrite(_latch, HIGH);
  delay(10);
  digitalWrite(_latch, LOW);
  _latched = true;
}

void LatchingRelay::unlatch()
{
  if(_unlatch == -1)
  {
    return;
  }
  
  digitalWrite(_unlatch, HIGH);
  delay(10);
  digitalWrite(_unlatch, LOW);
  _latched = false;
}

void LatchingRelay::toggle()
{
  if(_latched)
  {
    unlatch();
  }
  else
  {
    latch();
  }
}

int initRelays()
{
  if(NUMBER_OF_RELAYS > 0)
  {
    relays[0] = LatchingRelay(RELAY_1_LATCH_PIN, RELAY_1_UNLATCH_PIN);
  }
  if(NUMBER_OF_RELAYS > 1)
  {
    relays[1] = LatchingRelay(RELAY_2_LATCH_PIN, RELAY_2_UNLATCH_PIN);
  }
  if(NUMBER_OF_RELAYS > 2)
  {
    relays[2] = LatchingRelay(RELAY_3_LATCH_PIN, RELAY_3_UNLATCH_PIN);
  }
  if(NUMBER_OF_RELAYS > 3)
  {
    relays[3] = LatchingRelay(RELAY_4_LATCH_PIN, RELAY_4_UNLATCH_PIN);
  }
}
