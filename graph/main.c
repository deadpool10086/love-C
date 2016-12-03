#include "acllib.h"
#include <stdio.h>
int Setup()
{
	initConsole();
	printf("«Î ‰»ÎøÌ∂»£∫");
	int width;
	scanf("%d",&width);
	initWindow("hello",DEFAULT,DEFAULT,width,width);
	beginPaint();
	setPenColor(BLUE);
	setPenWidth(1);
	setPenStyle(PEN_STYLE_DASHDOTDOT);
	line(20,20,width-20,width-20);
	putPixel(100,150,RGB(255,0,255));
	endPaint();
	return 0;
}
