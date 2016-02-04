/*
 * Shooter.cpp
 *
 *  Created on: Feb 1, 2016
 *      Author: Benjamin
 */

#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter() :Subsystem("Shooter") {
	lMotor=new Talon(5);
	rMotor=new Talon(4);
}

void Shooter::InitDefaultCommand() {

}

void Shooter::shoot() {
	lMotor->SetSpeed(1.0);
	rMotor->SetSpeed(1.0);
}

Shooter::~Shooter(){
	delete lMotor;
	delete rMotor;
}
