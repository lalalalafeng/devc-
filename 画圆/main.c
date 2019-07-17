#include "acllib.h"
#include<stdio.h>
#include<math.h>
int Setup()
{
	//initConsole();
	//printf("请输入一个宽度\n");
	//int width;
	//scanf("%d", &width);

	initWindow("Hello", 0, 0, 500, 500);
	int x,y;
	for(x=0; x<=500; x+=1)
	{
		for(y=0; y<=500; y+=1)
		{
			if(pow(x-250,2)+pow(y-250,2) > pow(250, 2))
			{
				beginPaint();
				putPixel(x,y,BLUE);
				
				endPaint();
			}
		}
	}
	return 0;
}
