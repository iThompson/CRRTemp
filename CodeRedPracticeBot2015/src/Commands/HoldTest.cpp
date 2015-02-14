#include "HoldTest.h"

#include "SayHello.h"


HoldTest::HoldTest() {
	AddParallel(new SayHello());
}
