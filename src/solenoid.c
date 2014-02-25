#include "main.h"

void SolenoidTask(void *ignore) {
  while (1) {
    if (joystickGetDigital(1, 7, JOY_UP) || joystickGetDigital(2, 7, JOY_UP)) {
      solenoidSet(HIGH);
    }

    if (joystickGetDigital(1, 7, JOY_DOWN) || joystickGetDigital(2, 7, JOY_DOWN)) {
      solenoidSet(LOW);
    }

    taskDelay(25);
  }
}

void solenoidSet(bool value) {
  digitalWrite(SOLENOID_1, value);
  digitalWrite(SOLENOID_2, value);
}