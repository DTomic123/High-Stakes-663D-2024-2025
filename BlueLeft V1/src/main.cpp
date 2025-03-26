/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\663D                                             */
/*    Created:      Wed Sep 04 2024                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

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
// ClumpA               digital_out   A               
// ClumpB               digital_out   B               
// Controller1          controller                    
// Inertial             inertial      3               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
using namespace vex;
competition Competition;

void toggleClumpA() {
  if (ClumpA.value() == false) {
    ClumpA.set(true);
  }
  else {
    ClumpA.set(false);
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

void VictoryBlueLeft() {
Drivetrain.setDriveVelocity(10, percent);
Drivetrain.setStopping(brake);
Conveyor.setVelocity(100, percent);
Intake.setVelocity(100, percent);
Engage.setVelocity(100, percent);
Intake.setReversed(true);
ClumpA.set(true);
Drivetrain.driveFor(reverse,19,inches,true);
Drivetrain.setDriveVelocity(10, percent);
Drivetrain.driveFor(reverse,15,inches,true);
ClumpA.set(false);
Arm.set(true);
wait(0.5,seconds);
Arm.set(false); 
Engage.spin(forward);
wait(1,seconds);
Drivetrain.setDriveVelocity(15, percent);
Drivetrain.turnFor(right,85,degrees);
wait(1,seconds);
Drivetrain.driveFor(forward,16,inches);
Drivetrain.turnFor(right,160,degrees,true);
Drivetrain.driveFor(forward,30, inches);
Engage.stop();
}  

int current_auton_selection = 0;
bool auto_started = false;
void pre_auton() {
  vexcodeInit();
 

  while(!auto_started){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5, 40, "Battery Percentage:");
    Brain.Screen.printAt(5, 60, "%d", Brain.Battery.capacity());
    Brain.Screen.printAt(5, 80, "Chassis Heading Reading:");
    Brain.Screen.printAt(5, 120, "Selected Auton:");
    switch(current_auton_selection){
      case 0:
        Brain.Screen.printAt(5, 140, "Auton 1");
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
      VictoryBlueLeft();
      break;
  }
}

int main() {
  Competition.autonomous(autonomous);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}
