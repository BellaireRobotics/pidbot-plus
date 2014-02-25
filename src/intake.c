#include "main.h"

bool intakeContinuousToggle = false;

void IntakeTask(void *ignore) {
  while (1) {
    if (joystickGetDigital(1, 5, JOY_UP) || joystickGetDigital(2, 5, JOY_UP))
      intakeSet(127);
    else if (joystickGetDigital(1, 5, JOY_DOWN) || joystickGetDigital(2, 5, JOY_DOWN))
      intakeSet(-127);
    else if (intakeContinuousToggle)
      intakeSet(127);
    else
      intakeSet(0);

    taskDelay(25);
  }
}

void intakeSet(int speed) {
  motorSet(RIGHT_INTAKE, speed);
  motorSet(LEFT_INTAKE, speed);
}