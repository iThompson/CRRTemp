/*
 * InvertedIOButton.cpp
 *
 *  Created on: Feb 18, 2012
 *      Author: Programmer
 */

#include "InvertedIOButton.h"

const bool InvertedIOButton::kActiveState = true;

InvertedIOButton::InvertedIOButton(int port) : DigitalIOButton(port)
{
}
