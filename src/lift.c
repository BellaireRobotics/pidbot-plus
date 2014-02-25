#include "main.h"

void lift() {
  // ...
}

void liftSet(int speed) {
  motorSet(LEFT_TOP_LIFT, -speed);
  motorSet(LEFT_BOTTOM_LIFT, -speed);
  motorSet(RIGHT_TOP_LIFT, speed);
  motorSet(RIGHT_BOTTOM_LIFT, speed);
}