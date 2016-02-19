/*
 * XboxController.h
 *
 *  Created on: Jan 21, 2016
 *      Author: Steven
 */

#ifndef SRC_XBOXCONTROLLER_H_
#define SRC_XBOXCONTROLLER_H_

#include "WPILib.h"
#include "Vector.h"

class XboxController {
public:

	std::shared_ptr<Joystick> joystick;

	const int ButtonA = 1;
	const int ButtonB = 2;
	const int ButtonX = 3;
	const int ButtonY = 4;

	const int ButtonLB = 5;
	const int ButtonRB = 6;

	const int ButtonBack = 7;
	const int ButtonStart = 8;

	const int ButtonLeftJoystickPress = 9;
	const int ButtonRightJoystickPress = 10;

	const int LeftJoystickX = 0;
	const int LeftJoystickY = 1;
	const int RightJoystickX = 4;
	const int RightJoystickY = 5;

	const int LeftTrigger = 2;
	const int RightTrigger = 3;

	float LeftStickXOffset;
	float LeftStickYOffset;

	float RightStickXOffset;
	float RightStickYOffset;

	const int DPAD_UP = 0;
	const int DPAD_UP_RIGHT = 45;
	const int DPAD_RIGHT = 90;
	const int DPAD_DOWN_RIGHT = 135;
	const int DPAD_DOWN = 180;
	const int DPAD_DOWN_LEFT = 225;
	const int DPAD_LEFT = 270;
	const int DPAD_UP_LEFT = 315;

	const float LeftTriggerButtonThreshold = 0.8;
	const float RightTriggerButtonThreshold = 0.8;

	const float LeftTriggerOffset = 0.5f;
	const float RightTriggerOffset = 0.5f;

	Vector* GetStickVector(int xId, int yId, float xOffset, float yOffset);
	Vector* GetLeftStickVector();
	Vector* GetRightStickVector();

	bool GetButton(int buttonId);
	bool GetDPad(int DPadId);

	float GetTrigger(int TriggerId, float TriggerOffset);
	float GetLeftTrigger();
	float GetRightTrigger();

	void Calibrate();
	void Rumble(float value);

	XboxController(int port);
	virtual ~XboxController();
};

#endif /* SRC_XBOXCONTROLLER_H_ */
