#include "vex.h"
using namespace vex;
using signature = vision::signature;
using code = vision::code;

brain  Brain;
// VEXcode device constructors
motor Extendor = motor(PORT11,ratio18_1,true);
motor Conveyor = motor(PORT12, ratio18_1, false);
motor Intake = motor(PORT14, ratio18_1, false);
motor TopLeft = motor(PORT15, ratio6_1, true);
motor TopRight = motor(PORT16, ratio6_1, true);
motor UpperRight = motor(PORT17, ratio6_1, false);
motor UpperLeft = motor(PORT18, ratio6_1, false);
motor LowerLeft = motor(PORT19, ratio6_1, true);
motor LowerRight = motor(PORT20, ratio6_1, true);
digital_out Clump = digital_out(Brain.ThreeWirePort.A);
digital_out Arm = digital_out(Brain.ThreeWirePort.B);
controller Controller1 = controller(primary);
inertial Inertial = inertial(PORT3);
// VEXcode generated functions
bool RemoteControlCodeEnabled = true;
//Controller Variables/Inputs
bool Controller1RightShoulderControlMotorsStopped = true;
bool Controller1LeftShoulderControlMotorsStopped = true;
bool Controller1ArrowsMotorsStopped = true;
bool Controller1ButtonsMotorsStopped = true;
// defines a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  wait(20,msec);
  while(true) {
    if(RemoteControlCodeEnabled) {
      // Button Configuration on Controller1
      if (Controller1.ButtonR1.pressing()) {
        Intake.spin(reverse);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonR2.pressing()) {
        Intake.spin(forward);
        Controller1RightShoulderControlMotorsStopped = false;
      } else if (!Controller1RightShoulderControlMotorsStopped) {
        Intake.stop();
        Controller1RightShoulderControlMotorsStopped = true;
      }
         if (Controller1.ButtonL1.pressing()) {
        Conveyor.spin(forward);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonL2.pressing()) {
        Conveyor.spin(reverse);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (!Controller1LeftShoulderControlMotorsStopped) {
        Conveyor.stop();
        Controller1LeftShoulderControlMotorsStopped = true;
      }
    }
    if (RemoteControlCodeEnabled){
       if (Controller1.ButtonY.pressing()) {
        Intake.spin(forward);
        Conveyor.spin(forward);
        Controller1ArrowsMotorsStopped = false;
      } else if (Controller1.ButtonRight.pressing()) {
        Intake.spin(reverse);
        Conveyor.spin(reverse);
        Controller1ArrowsMotorsStopped = false;
      } else if (!Controller1ArrowsMotorsStopped) {
        Conveyor.stop();
        Intake.stop();
        Controller1ArrowsMotorsStopped = true;
      }
      if (Controller1.ButtonX.pressing()) {
        Extendor.spin(forward);
        Controller1ButtonsMotorsStopped = false;
      } else if (Controller1.ButtonUp.pressing()) {
        Extendor.spin(reverse);
        Controller1ButtonsMotorsStopped = false;
      } else if (!Controller1ButtonsMotorsStopped) {
        Extendor.stop();
        Controller1ButtonsMotorsStopped = true;
      }
    }
    }
    wait(20, msec);
  }
void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}
