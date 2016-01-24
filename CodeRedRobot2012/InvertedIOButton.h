/*
 * InvertedIOButton.h
 *
 *  Created on: Feb 18, 2012
 *      Author: Programmer
 */

#ifndef INVERTEDIOBUTTON_H_
#define INVERTEDIOBUTTON_H_

#include <Buttons/DigitalIOButton.h>

class InvertedIOButton: public DigitalIOButton {
public:
	static const bool kActiveState;
	
	InvertedIOButton(int port);
	virtual ~InvertedIOButton() {}
};

#endif /* INVERTEDIOBUTTON_H_ */
