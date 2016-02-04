/*
 * DriveTrain.cpp
 *
 *  Created on: Feb 1, 2016
 *      Author: Benjamin
 */

#include "DriveTrain.h"
#include "../RobotMap.h"

DriveTrain::DriveTrain(RobotDrive drive) :Subsystem("DriveTrain") {
	robot = drive;
}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void DriveTrain::drive(float lSpeed, float rSpeed) {
	robot->SetLeftRightMotorOutputs(lSpeed, rSpeed);
}


