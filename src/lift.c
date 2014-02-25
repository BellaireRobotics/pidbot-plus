#include "main.h"

#define LIFT_MINIMUM_HEIGHT     0
#define LIFT_FLOOR_HEIGHT       0
#define LIFT_BUMP_HEIGHT        150
#define LIFT_STASH_HEIGHT       1100
#define LIFT_HANG_HEIGHT        1280

int   pidRunning = false;
float pidRequestedValue = 0;

void LiftTask(void *ignore) {
  int counts;

  while (1) {
    imeGet(IME_LIFT, &counts);

    if (joystickGetDigital(1, 8, JOY_UP) || joystickGetDigital(2, 8, JOY_UP)) { // check stash waypoint
      pidRequestedValue = LIFT_STASH_HEIGHT;
    } else if (joystickGetDigital(1, 8, JOY_LEFT) || joystickGetDigital(2, 8, JOY_LEFT)) { // check bump waypoint
      pidRequestedValue = LIFT_BUMP_HEIGHT;
    } else if (joystickGetDigital(1, 8, JOY_DOWN) || joystickGetDigital(2, 8, JOY_DOWN)) { // check floor waypoint
      pidRequestedValue = LIFT_FLOOR_HEIGHT;
    } else if (joystickGetDigital(1, 8, JOY_RIGHT) || joystickGetDigital(2, 8, JOY_RIGHT)) { // check hang waypoint
      pidRequestedValue = LIFT_HANG_HEIGHT;
    } else if (joystickGetDigital(1, 6, JOY_UP) || joystickGetDigital(2, 6, JOY_UP)) { // if trigger up, turn PID off and override motors up, then turn PID on for the new position
      pidRunning = false;
      liftSet(127);
      pidRequestedValue = counts;
    } else if (joystickGetDigital(1, 6, JOY_DOWN) || joystickGetDigital(2, 6, JOY_DOWN)) { // if trigger up, turn PID off and override motors up, then turn PID on for the new position
      pidRunning = false;
      liftSet(-127);
      pidRequestedValue = counts;
    } else { // else keep running PID
      pidRunning = true;
    }

    taskDelay(25); // limit update rate of lift control, useful for future PID setpoint changes
  }
}

void liftSet(int speed) {
  motorSet(LEFT_TOP_LIFT, -speed);
  motorSet(LEFT_BOTTOM_LIFT, -speed);
  motorSet(RIGHT_TOP_LIFT, speed);
  motorSet(RIGHT_BOTTOM_LIFT, speed);
}