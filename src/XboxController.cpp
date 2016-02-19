/*
 * XboxController.cpp
 *
 *  Created on: Jan 21, 2016
 *      Author: Steven
 */

#include "XboxController.h"
#include "Math.h"

XboxController::XboxController(int port) {
	joystick = std::shared_ptr<Joystick>(new Joystick(port));

	LeftStickXOffset = 0;
	LeftStickYOffset = 0;

	RightStickXOffset = 0;
	RightStickYOffset = 0;
}

Vector* XboxController::GetStickVector(int xId, int yId, float xOffset, float yOffset) {
	float x = joystick->GetRawAxis(xId) - xOffset;
	float y = joystick->GetRawAxis(yId) - yOffset;

	return new Vector(x, y);
}

Vector* XboxController::GetLeftStickVector() {
	return GetStickVector(LeftJoystickX, LeftJoystickY, LeftStickXOffset, LeftStickYOffset);
}

Vector* XboxController::GetRightStickVector() {
	return GetStickVector(RightJoystickX, RightJoystickY, RightStickXOffset, RightStickYOffset);
}

bool XboxController::GetButton(int buttonId) {
	if (buttonId == LeftTrigger){
		return GetTrigger(LeftTrigger, LeftTriggerOffset) >= LeftTriggerButtonThreshold;
	}

	else if (buttonId == RightTrigger){
		return GetTrigger(RightTrigger, RightTriggerOffset) >= RightTriggerButtonThreshold;
	}

	else {
		return joystick->GetRawButton(buttonId);
	}
}

bool XboxController::GetDPad(int DPadId) {
	DPadId = joystick->GetPOV();
	return DPadId;
}

float XboxController::GetTrigger (int TriggerId, float trigger_offset) {
	float rawValue = joystick->GetRawAxis(TriggerId);
	return (rawValue - trigger_offset) * 2;
}

float XboxController::GetLeftTrigger() {
	return GetTrigger(LeftTrigger, LeftTriggerOffset);
}

float XboxController::GetRightTrigger() {
	return GetTrigger(RightTrigger, RightTriggerOffset);
}

void XboxController::Rumble(float value) {
	joystick->SetRumble(Joystick::RumbleType::kLeftRumble, value);
	joystick->SetRumble(Joystick::RumbleType::kRightRumble, value);
}

void XboxController::Calibrate() {
	LeftStickXOffset = joystick->GetRawAxis(LeftJoystickX);
	LeftStickYOffset = joystick->GetRawAxis(LeftJoystickY);

	RightStickXOffset = joystick->GetRawAxis(RightJoystickX);
	RightStickYOffset = joystick->GetRawAxis(RightJoystickY);
}

XboxController::~XboxController() {}
