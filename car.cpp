#include<graphics.h>
#include<conio.h>
#include<dos.h>

int main()
{
	initwindow(800, 800);
	
	for(int i = 0; i < 1800; i++)
	{
		line(250+i, 250, 450+i, 250);
		circle(200+i, 250, 50);
		circle(500+i, 250, 50);
		line(130+i, 250, 150+i, 250);
		line(550+i, 250, 570+i,250);
		line(130+i, 250, 130+i, 170);
		line(570+i, 250, 570+i, 170);
		line(130+i, 170, 570+i, 170);
		line(230+i, 170, 270+i, 100);
		line(480+i, 170, 440+i, 100);
		line(270+i, 100, 440+i, 100);
		line(350+i, 100, 350+i, 250);
		line(249+i, 160, 275+i, 110);
		line(275+i, 110, 340+i, 110);
		line(340+i, 110, 340+i, 160);
		line(249+i, 160, 340+i, 160);	
		line(462+i, 160, 435+i, 110);
		line(435+i, 110, 360+i, 110);
		line(462+i, 160, 360+i, 160);
		line(360+i, 110, 360+i, 160);
		circle(200+i, 250, 30);
		circle(500+i, 250, 30);
		arc(200+i, 250, 0, 180, 60);
		arc(500+i, 250, 0, 180, 60);
		
		delay(5);
		cleardevice();
		line(0, 300, 1750, 300);
	}

//	CODE TO GENERATE THE CAR. 

//	line(250, 250, 450, 250);
//	circle(200, 250, 50);
//	circle(500, 250, 50);
//	line(130, 250, 150, 250);
//	line(550, 250, 570,250);
//	line(130, 250, 130, 170);
//	line(570, 250, 570, 170);
//	line(130, 170, 570, 170);
//	line(230, 170, 270, 100);
//	line(480, 170, 440, 100);
//	line(270, 100, 440, 100);
//	line(350, 100, 350, 250);
//	line(249, 160, 275, 110);
//	line(275, 110, 340, 110);
//	line(340, 110, 340, 160);
//	line(249, 160, 340, 160);
//	line(462, 160, 435, 110);
//	line(435, 110, 360, 110);
//	line(462, 160, 360, 160);
//	line(360, 110, 360, 160);
//	circle(200, 250, 30);
//	circle(500, 250, 30);
//	arc(200, 250, 0, 180, 60);
//	arc(500, 250, 0, 180, 60);
//	line(0, 300, 1750, 300);
	
	getch();
   	closegraph();
}
