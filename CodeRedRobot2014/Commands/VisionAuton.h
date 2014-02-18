#ifndef VISIONAUTON_H
#define VISIONAUTON_H

#include "Commands/CommandGroup.h"

/**
 *
 *
 * @author Devon Loehr
 */
class VisionAuton: public CommandGroup {
public:	
	VisionAuton();
	
	bool m_hasHotGoal;
};

#endif
