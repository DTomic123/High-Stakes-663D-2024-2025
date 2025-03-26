#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor Conveyor = motor(PORT12, ratio18_1, false);
motor Intake = motor(PORT14, ratio18_1, false);
motor UpperRight = motor(PORT17, ratio6_1, true);
motor UpperLeft = motor(PORT18, ratio6_1, false);
motor TopLeft = motor(PORT15, ratio6_1, true);
motor TopRight = motor(PORT16, ratio6_1, false);
motor LowerLeft = motor(PORT19, ratio6_1, true);
motor LowerRight = motor(PORT20, ratio6_1, false);
digital_out Clump = digital_out(Brain.ThreeWirePort.A);
digital_out Arm = digital_out(Brain.ThreeWirePort.B);
controller Controller1 = controller(primary);
motor_group RightDrive = motor_group(TopRight,LowerRight,UpperRight);
motor_group LeftDrive = motor_group(TopLeft,LowerLeft,UpperLeft);
motor_group Engage = motor_group(Conveyor,Intake);
drivetrain Drivetrain = drivetrain (LeftDrive,RightDrive,320,320,40,mm,.75);



// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}