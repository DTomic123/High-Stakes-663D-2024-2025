#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Conveyor             motor         13              
// Intake               motor         14              
// TopLeft              motor         15              
// TopRight             motor         16              
// UpperRight           motor         17              
// UpperLeft            motor         18              
// LowerLeft            motor         19              
// LowerRight           motor         20              
// BangA                digital_out   A               
// BangB                digital_out   B               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;
competition Competition;
Drive chassis(
ZERO_TRACKER_NO_ODOM,
motor_group(LowerLeft,UpperLeft,TopLeft),
motor_group(LowerRight,UpperRight,TopRight),
PORT3,
3.75,
0.75,
360,
//LF:      //RF:    
PORT1,     -PORT2,
//LB:      //RB: 
PORT3,     -PORT4,
3,
2.75,
-2,
1,
-2.75,
5.5
);
int current_auton_selection = 0;
bool auto_started = false;
void pre_auton() {
  vexcodeInit();
  default_constants();

  while(!auto_started){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5, 20, "JAR Template v1.2.0");
    Brain.Screen.printAt(5, 40, "Battery Percentage:");
    Brain.Screen.printAt(5, 60, "%d", Brain.Battery.capacity());
    Brain.Screen.printAt(5, 80, "Chassis Heading Reading:");
    Brain.Screen.printAt(5, 100, "%f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5, 120, "Selected Auton:");
    switch(current_auton_selection){
      case 0:
        Brain.Screen.printAt(5, 140, "Auton 1");
        break;
      case 1:
        Brain.Screen.printAt(5, 140, "Auton 2");
        break;
      case 2:
        Brain.Screen.printAt(5, 140, "Auton 3");
        break;
      case 3:
        Brain.Screen.printAt(5, 140, "Auton 4");
        break;
      case 4:
        Brain.Screen.printAt(5, 140, "Auton 5");
        break;
      case 5:
        Brain.Screen.printAt(5, 140, "Auton 6");
        break;
      case 6:
        Brain.Screen.printAt(5, 140, "Auton 7");
        break;
      case 7:
        Brain.Screen.printAt(5, 140, "Auton 8");
        break;
    }
    if(Brain.Screen.pressing()){
      while(Brain.Screen.pressing()) {}
      current_auton_selection ++;
    } else if (current_auton_selection == 1){
      current_auton_selection = 0;
    }
    task::sleep(10);
  }
}
void autonomous(void) {
  auto_started = true;
  switch(current_auton_selection){ 
    case 0:
      drive_test();
      break;
    case 1:         
      drive_test();
      break;
    case 2:
      turn_test();
      break;
    case 3:
      swing_test();
      break;
    case 4:
      full_test();
      break;
    case 5:
      odom_test();
      break;
    case 6:
      tank_odom_test();
      break;
    case 7:
      holonomic_odom_test();
      break;
    
 }
}

void toggleClump() {
  if (Clump.value() == false) {
    Clump.set(true);
  }
  else {
    Clump.set(false);
  }
}

void toggleArm() {
  if (Arm.value() == false) {
    Arm.set(true);
    
  }
  else {
    Arm.set(false);
  }
}
void usercontrol(void) {
  Intake.setVelocity(100,percent);
  Conveyor.setVelocity(100,percent);
  Extendor.setVelocity(5, percent);
  wait(10, msec);
  while (true) {

    Controller1.ButtonA.pressed(toggleClump);
    Controller1.ButtonB.pressed(toggleClump);
    Controller1.ButtonLeft.pressed(toggleArm);
    Controller1.ButtonDown.pressed(toggleArm);

    
    
    chassis.control_arcade();

    wait(20, msec); 
  }
}
int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();
  
  while (true) {
    wait(100, msec);
  }
}
