/*
 * AutonomousMode.h
 *
 *  Created on: Feb 18, 2016
 *      Author: Benjamin
 */

#ifndef AUTONOMOUSMODE_H
#define AUTONOMOUSMODE_H


class AutonomousMode{

private:

public:
	int slotnum;
	enum slot{slot1, slot2, slot3};

	AutonomousMode(int slot): slotnum(slot){};
};



#endif /* SRC_AUTONOMOUSMODES_H_ */
