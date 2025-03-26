using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor Conveyor;
extern motor Intake;
extern motor TopLeft;
extern motor TopRight;
extern motor UpperRight;
extern motor UpperLeft;
extern motor LowerLeft;
extern motor LowerRight;
extern digital_out ClumpA;
extern digital_out Arm;
extern controller Controller1;
extern inertial Inertial;
extern motor_group RightDrive;
extern motor_group LeftDrive;
extern motor_group Engage;
extern drivetrain Drivetrain;
extern smartdrive Smartdrive;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );