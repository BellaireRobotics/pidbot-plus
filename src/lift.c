#include "main.h"

#define LIFT_MINIMUM_HEIGHT     0
#define LIFT_FLOOR_HEIGHT       0
#define LIFT_BUMP_HEIGHT        150
#define LIFT_STASH_HEIGHT       1100
#define LIFT_HANG_HEIGHT        1280

void LiftTask(void *ignore) {
  int counts;

  while (1) {
    imeGet(IME_LIFT, &counts); // get lift encoder count

    if (joystickGetDigital(1, 8, JOY_UP) || joystickGetDigital(2, 8, JOY_UP)) { // check stash waypoint
      liftPIDRequestedValue = LIFT_STASH_HEIGHT;
    } else if (joystickGetDigital(1, 8, JOY_LEFT) || joystickGetDigital(2, 8, JOY_LEFT)) { // check bump waypoint
      liftPIDRequestedValue = LIFT_BUMP_HEIGHT;
    } else if (joystickGetDigital(1, 8, JOY_DOWN) || joystickGetDigital(2, 8, JOY_DOWN)) { // check floor waypoint
      liftPIDRequestedValue = LIFT_FLOOR_HEIGHT;
    } else if (joystickGetDigital(1, 8, JOY_RIGHT) || joystickGetDigital(2, 8, JOY_RIGHT)) { // check hang waypoint
      liftPIDRequestedValue = LIFT_HANG_HEIGHT;
    } else if (joystickGetDigital(1, 6, JOY_UP) || joystickGetDigital(2, 6, JOY_UP)) { // if trigger up, turn PID off and override motors up, then turn PID on for the new position
      mutexTake(liftMutex, ULONG_MAX);
      liftSet(127);
      liftPIDRequestedValue = counts;
      mutexGive(liftMutex);
    } else if (joystickGetDigital(1, 6, JOY_DOWN) || joystickGetDigital(2, 6, JOY_DOWN)) { // if trigger up, turn PID off and override motors up, then turn PID on for the new position
      mutexTake(liftMutex, ULONG_MAX);
      liftSet(-127);
      liftPIDRequestedValue = counts;
      mutexGive(liftMutex);
    }

    taskDelay(25);
  }
}

void liftSet(int speed) {
  motorSet(LEFT_TOP_LIFT, -speed);
  motorSet(LEFT_BOTTOM_LIFT, -speed);
  motorSet(RIGHT_TOP_LIFT, speed);
  motorSet(RIGHT_BOTTOM_LIFT, speed);
}
