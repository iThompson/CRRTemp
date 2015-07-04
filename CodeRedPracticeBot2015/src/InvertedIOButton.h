/*
 * InvertedIOButton.h
 *
 *  Created on: Feb 11, 2015
 *      Author: Zachary Stillman
 */

#ifndef SRC_INVERTEDIOBUTTON_H_
#define SRC_INVERTEDIOBUTTON_H_

#include "GenericHID.h"
#include "Buttons/JoystickButton.h"

class InvertedIOButton : public JoystickButton
{
public:
	InvertedIOButton(GenericHID *joystick, int buttonNumber);
	virtual ~InvertedIOButton() {}
//	virtual bool Grab();

	virtual bool Get();

private:

};



#endif /* SRC_INVERTEDIOBUTTON_H_ */
