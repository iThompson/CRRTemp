#include <math.h>
#include <stdio.h>

#define PI 3.1415926535897932384626433832795028841

// aheight, bheight, and deltaab are constant.
// Everything is in radians.
double calculate(double aheight, double bheight, double atheta, double btheta, double abdelta) {
	double adelta = aheight / tan(atheta);
	double bdelta = bheight / tan(btheta);
	
	double outertheta = acos((-pow(adelta, 2) + pow(bdelta, 2) + pow(abdelta, 2)) / (2 * bdelta * abdelta));
	double innertheta = acos((-pow(abdelta, 2) + pow(adelta, 2) + pow(bdelta, 2)) / (2 * adelta * bdelta));
	
	return outertheta + (innertheta / 2) - (PI / 2);
}

int main() {
	printf("Angle: %f", calculate(60, 60, 0.34147242, 0.3522269, 20));
}
