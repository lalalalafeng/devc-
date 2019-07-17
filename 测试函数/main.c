#include"acllib.h"
int Setup()
{
	initWindow("盾牌", DEFAULT, DEFAULT, 500, 500);
	//setPenColor(RED);
	//setPenWidth(1);

	beginPaint();
/*	putPixel(30,30,BLACK);		
	putPixel(450,450,BLACK);		 
	putPixel(240,240,BLACK);		//圆心 
*/
	setBrushColor(RGB(255,5,37));
	ellipse( 30, 30, 450, 450);		//画圆 
	setBrushColor(RGB(220,230,240));			//银色 
	ellipse( 80, 80, 400, 400);
	setBrushColor(RGB(255,5,37));		//红色 
	ellipse(120, 120, 360, 360);
	setBrushColor(BLUE);			//蓝色 
	ellipse(180, 180, 300, 300);
	setBrushColor(RGB(220,230,240));
	POINT p1[] = {
		{240,180},
		{223,220},
		{183,220},
		{220,240},
		{200,280},
		{240,253},
		{280,280},
		{260,240},
		{296,220},
		{257,220},
	};
	polygon(p1, 10);
	
	
	//setBrushColor(WHITE);
	//ellipse( 120, 120, 360, 360);
//	arc( 120, 120, 360, 360, 30, 30, 30, 30);
/*	line( 30, 30, 450, 450);
	line( 450, 30, 30, 450);
	
		
	line(180, 240, 240, 300);
	line(240, 300, 300, 240);
	line(300, 240, 240, 180);
	line(240, 180, 180, 240);   */
/*	POINT star_xy[points] = {
			{230, 170}, {170, 230}, {230, 290}, {290, 230} 
		};
	setPenColor(BLACK);
	polygon(star_xy, 4);
*/	//画出坐标系
/*	int x, y;
	for(x=30; x<=450; x+=10)
	{
		for(y=30; y<=450; y+=10)
		{
			beginPaint();
			if(x==240 || y==240)
			{
				setPenColor(GREEN);
			}else
			{
				setPenColor(BLACK);
			}
			line(x, y, 450,y);
			line( x, y, x, 450);
			endPaint();
		}
		
	}
*/
	endPaint();
	
	return 0;
}
