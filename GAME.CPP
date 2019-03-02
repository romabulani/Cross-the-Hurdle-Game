#include<graphics.h>
#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>

union REGS i, o;

int initmouse()
{
   i.x.ax = 0;

   int86(0X33, &i, &o);
   return ( o.x.ax );
}
int callmouse()
{
	      i.x.ax=1;
	      int86(51,&i,&o);
	      return 1;
}
void mouseposi(int &xpos,int &ypos,int &button)
       {
	      i.x.ax=3;
	      int86(51,&i,&o);
	      button=o.x.bx;
	      xpos=o.x.cx;
	      ypos=o.x.dx;
	}
void drawman(int i,int j)
   {
       //for head
    circle(40+i,360-j,10);
   circle(35+i,357-j,1.5);
   circle(45+i,357-j,1.5);
   arc(40+i,364-j,180,0,2);

   //for neck
   line(35+i,368-j,35+i,378-j);
   line(45+i,368-j,45+i,378-j);
   line(45+i,368-j,45+i,378-j);

   //For centre part
   setcolor(RED);
   rectangle(27+i,378-j,53+i,395-j);
   circle(40+i,382-j,2);
   circle(40+i,390-j,2);

   //for left legs
   setcolor(GREEN);
   line(27+i,395-j,24+i,420-j);
   line(53+i,395-j,56+i,420-j);

   //for right legs
   line(40+i,400-j,32+i,425-j);
   line(40+i,400-j,48+i,425-j);

    //for left shoes
    setcolor(LIGHTBLUE);
   line(24+i,420-j,21+i,425-j);
   line(21+i,425-j,32+i,425-j);
   //for right shoes
   line(56+i,420-j,59+i,425-j);
   line(48+i,425-j,59+i,425-j);

   //for left hand
   line(27+i,378-j,17+i,388-j);
   line(27+i,384-j,18+i,394-j);
   circle(16+i,392-j,2);

   //for right hand
   line(53+i,378-j,63+i,388-j);
   line(53+i,384-j,64+i,394-j);
   circle(65+i,392-j,2);

   //for hair
   arc(40+i,355-j,0,180,10);
   }
void fillcolorinman(int i,int j)
{
//for head
    circle(40+i,360-j,10);
   circle(35+i,357-j,1.5);
   circle(45+i,357-j,1.5);
   arc(40+i,364-j,180,0,2);

   //for neck
   line(35+i,368-j,35+i,378-j);
   line(45+i,368-j,45+i,378-j);
   line(45+i,368-j,45+i,378-j);

   //For centre part

   rectangle(27+i,378-j,53+i,395-j);
   circle(40+i,382-j,2);
   circle(40+i,390-j,2);

   //for left legs

   line(27+i,395-j,24+i,420-j);
   line(53+i,395-j,56+i,420-j);

   //for right legs
   line(40+i,400-j,32+i,425-j);
   line(40+i,400-j,48+i,425-j);

    //for left shoes

   line(24+i,420-j,21+i,425-j);
   line(21+i,425-j,32+i,425-j);
   //for right shoes
   line(56+i,420-j,59+i,425-j);
   line(48+i,425-j,59+i,425-j);

   //for left hand
   line(27+i,378-j,17+i,388-j);
   line(27+i,384-j,18+i,394-j);
   circle(16+i,392-j,2);

   //for right hand
   line(53+i,378-j,63+i,388-j);
   line(53+i,384-j,64+i,394-j);
   circle(65+i,392-j,2);

   //for hair
   arc(40+i,355-j,0,180,10);
   }


void obstacle()
{
     line(0,425,600,425);
    rectangle(214,375,270,425);
    line(590,425,590,375);
    rectangle(580,355,650,375);
    outtextxy(582,360,"THE END");
}

void main()
{
int gd=DETECT,gm,button,x,y,r;
int i,j,flag=0,c,k=0;
initgraph(&gd,&gm,"C:/TURBOC3/BGI");
for(i=0;i<600;i=i)
{
	delay(500);
	cleardevice();
	callmouse();
	if(i>=140&&i<=180)
	{
		mouseposi(x,y,button);
		if(button==1)
		{
			for(j=0;j<4;j++)
			{
				obstacle();
				drawman(i,50);
				i=i+30;
				delay(500);
				if(j==3)
					continue;
				else
				{
					outtextxy(200,200,"50+");
					cleardevice();
				}

			}
		}
		else
		{
			if(button!=1)
			{
				flag++;
				break;
			}
		}
	}
	else
	{
		obstacle();
		drawman(i,0);
		delay(200);
		if(i>240&&i<390)
		{
			setcolor(YELLOW);
			ellipse(330+k,400,0,360,3,3);
			fillellipse(330+k,400,3,3);

			setcolor(BLUE);
			outtextxy(200,200,"50+");
			k=k+30;
		}
		i=i+30;
	}

}

if(flag!=0)
{
    cleardevice();
    outtextxy(200,200,"GAME OVER!!!");
}
else
{
    cleardevice();
    outtextxy(200,150,"LEVEL COMPLETED!!!");
    outtextxy(200,300,"CURRENT SCORE IS 250");
}
getch();
closegraph();
}
