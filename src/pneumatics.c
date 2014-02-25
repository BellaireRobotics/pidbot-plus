#include "main.h"

void pneumatics() {
  if (joystickGetDigital(1, 7, JOY_UP) || joystickGetDigital(2, 7, JOY_UP))
    pneumaticsSet(HIGH);

  if (joystickGetDigital(1, 7, JOY_DOWN) || joystickGetDigital(2, 7, JOY_DOWN)) 
    pneumaticsSet(LOW);
}

void pneumaticsSet(bool value) {
  digitalWrite(PNEUMATICS_LOCK_1, value);
  digitalWrite(PNEUMATICS_LOCK_2, value);
}