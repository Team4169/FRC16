/*
 * Shooter.h
 *
 *  Created on: Feb 1, 2016
 *      Author: Benjamin
 */

#ifndef SHOOTER_H
#define SHOOTER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Shooter: Subsystem {

private:
	Talon* lMotor;
	Talon* rMotor;

public:
	Shooter();
	void InitDefaultCommand();
	void shoot();
	~Shooter();

};



#endif /* SRC_SUBSYSTEMS_SHOOTER_H_ */
