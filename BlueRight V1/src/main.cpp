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
void EngageLoop(){
  Engage.spin(forward);
}
void VictoryBlueRight() {
//Setup
Drivetrain.setDriveVelocity(20, percent);
Conveyor.setVelocity(100, percent);
Intake.setVelocity(100, percent);
Engage.setVelocity(100, percent);
Intake.setReversed(true);
Clump.set(true); 
//Clamp Goal
Drivetrain.driveFor(reverse,19,inches,true);
Drivetrain.setDriveVelocity(10, percent);
Drivetrain.driveFor(reverse,15,inches,true);
Clump.set(false); 
Arm.set(true);
wait(.5,seconds); 
Arm.set(false);
EngageLoop();
//Gain Single Ring
Drivetrain.setDriveVelocity(15, percent);
Drivetrain.turnFor(left,89,degrees);
Drivetrain.driveFor(forward,16,inches);
Drivetrain.driveFor(reverse,5,inches,true);
wait(1,seconds);
//Gain Double Ring
Drivetrain.turnFor(left,80,degrees,true);
Drivetrain.setDriveVelocity(10, percent);
Drivetrain.driveFor(forward,19.5,inches);
Drivetrain.driveFor(reverse,8,inches,true);
Drivetrain.turnFor(right,39,degrees);
Drivetrain.setDriveVelocity(20, percent);
Drivetrain.driveFor(forward, 10, inches);
wait(1,seconds);
//Touch Bar
Drivetrain.driveFor(reverse,10,inches);
Drivetrain.turnFor(left,150,degrees);
Drivetrain.driveFor(forward,30,inches);
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
      VictoryBlueRight();
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
