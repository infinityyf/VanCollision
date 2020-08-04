#include "pointHull.h"


int main()
{
	VanPointHull demo(100);
	if (demo.Construct(256, 240, 4, 4))
		demo.Start();

	return 0;
}