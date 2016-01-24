/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2011. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "InvertedIOButton.h"
#include "DriverStation.h"

const bool InvertedIOButton::kActiveState = true;

InvertedIOButton::InvertedIOButton(int port) :
	m_port(port)
{
}

bool InvertedIOButton::Get()
{
	return DriverStation::GetInstance()->GetEnhancedIO().GetDigital(m_port) == kActiveState;
}
