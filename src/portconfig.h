// ==================
// Port Configuration 
// ==================

// -------------------------------
// Output (Motors and Digital Out)
// -------------------------------
// Motor 1 shares 4 amp max with Motors 2 - 5.
// Motor 10 shares 4 amp max with Motors 6 - 9.
// 4 amps for each motor group (1-5, 6-10).

// Intake
#define RIGHT_INTAKE 1
#define LEFT_INTAKE 10

// Wheels
#define RIGHT_FRONT 2
#define RIGHT_BACK 3
#define LEFT_FRONT 8
#define LEFT_BACK 9

// Lift
#define RIGHT_TOP_LIFT 4
#define RIGHT_BOTTOM_LIFT 5
#define LEFT_TOP_LIFT 6
#define LEFT_BOTTOM_LIFT 7

// Pneumatic Locks (Digital out)
#define PNEUMATICS_LOCK_1 11
#define PNEUMATICS_LOCK_2 12

// ---------------
// Input (Sensors)
// ---------------

#define IME_LIFT 0
#define AUTON_SELECT_POT 2
