/*
 * InvertedIOButton.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: Zachary Stillman
 */

#include "InvertedIOButton.h"

InvertedIOButton::InvertedIOButton(GenericHID *joystick, int buttonNumber) :
		JoystickButton(joystick, buttonNumber)
{

}

//bool InvertedIOButton::Grab() {
//	if(!Get()) {
//		return true;
//	}
//	else if(m_table != NULL) {
//		return m_table->GetBoolean("pressed");
//	}
//	else {
//		return false;
//	}
//}

bool InvertedIOButton::Get() {
	return !JoystickButton::Get();
}


