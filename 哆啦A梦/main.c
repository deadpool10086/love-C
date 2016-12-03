#include "acllib.h"
#include <stdio.h>
int Setup()
{
	
	initWindow("hello",DEFAULT,DEFAULT,576,699);
	beginPaint();
	setPenWidth(3);
	setBrushColor(BLUE);
	ellipse(69,9,503,402);
	chrod(100,-100,539,433,441,429,527,133);
	endPaint();
	return 0;
}
