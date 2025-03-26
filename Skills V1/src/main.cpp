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


void HighStakesSkills() {

//Starting Variables
Drivetrain.setDriveVelocity(8, percent);
Drivetrain.setTimeout(2,seconds);
Conveyor.setVelocity(100, percent);
Intake.setVelocity(100, percent);
Engage.setVelocity(100, percent);
Intake.setReversed(true);

//Red Right 
Clump.set(true);
Drivetrain.driveFor(reverse,6,inches);
Clump.set(false);
Arm.set(true);
wait(1,seconds); 
Drivetrain.setDriveVelocity(19, percent);
Arm.set(false);
Engage.spin(forward);
Drivetrain.turnFor(left,64,degrees);
Drivetrain.driveFor(forward,18,inches);
wait(2,seconds);
Drivetrain.driveFor(reverse,13,inches);
Drivetrain.turnFor(left,45,degrees);
Drivetrain.driveFor(forward,14,inches);
wait(2,seconds);
Drivetrain.turnFor(right,20,degrees);
Drivetrain.driveFor(forward,10,inches);
wait(2,seconds);
Drivetrain.turnFor(left,100,degrees);
Drivetrain.driveFor(forward,28,inches);
Drivetrain.turnFor(left,97,degrees);
Drivetrain.driveFor(forward,23,inches);
Drivetrain.turnFor(right,58,degrees);
Drivetrain.driveFor(reverse,48,inches);
Clump.set(true);
Engage.stop();

//Red Left Traverse
Drivetrain.driveFor(forward,15,inches);
Drivetrain.turnFor(right,144,degrees);
Drivetrain.setDriveVelocity(100, percent);
Drivetrain.driveFor(reverse,50,inches);
Drivetrain.setDriveVelocity(9, percent);
Drivetrain.driveFor(reverse,26,inches);
Clump.set(false);
Engage.spin(forward);

//Red Left
Drivetrain.setDriveVelocity(19, percent);
Drivetrain.turnFor(left,96,degrees);
Drivetrain.driveFor(forward,22,inches);
wait(1, seconds);
Drivetrain.turnFor(left,99,degrees);
Drivetrain.driveFor(forward,22,inches);
wait(1, seconds);
Drivetrain.turnFor(left,87,degrees);
Drivetrain.driveFor(forward,20,inches);
wait(1,seconds);
Drivetrain.turnFor(right,44,degrees);
wait(2,seconds);
Drivetrain.driveFor(forward,10,inches);
wait(1,seconds);
Drivetrain.turnFor(right,300,degrees);
Drivetrain.driveFor(reverse,10,inches);
Clump.set(true);
Engage.stop();

//Haunted Hang
Drivetrain.driveFor(forward,10,inches);
Drivetrain.turnFor(right,38,degrees);
Arm.set(true);
wait(1,seconds);
Drivetrain.driveFor(forward,20,inches);
Drivetrain.setDriveVelocity(40, percent);
Drivetrain.driveFor(forward,30,inches);
Drivetrain.setDriveVelocity(8, percent);
Drivetrain.driveFor(forward,18,inches);



/*Backpack and Clamp Blue 
Drivetrain.driveFor(forward,20,inches);
Drivetrain.setDriveVelocity(19, percent);
Engage.spin(forward);
Drivetrain.driveFor(forward,250,inches);
Engage.stop();
Drivetrain.turnFor(left,230,degrees);
Drivetrain.driveFor(reverse,30,inches);
Drivetrain.setDriveVelocity(9, percent);
Drivetrain.driveFor(reverse,15,inches);
Clump.set(false);
wait(1,seconds);
Engage.spin(forward);
*/





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
      HighStakesSkills();
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
