#include "WarlockAuton.h"
#include "Acquirer/ReverseBelt.h"
#include "Loader/LoaderLoad.h"

WarlockAuton::WarlockAuton() {
    // Ball 1    
	AddSequential(new ReverseBelt(true), 2.0);
      
	// Ball 2
	AddParallel(new LoaderLoad());
	AddSequential(new ReverseBelt(true));
}
