#include<dos.h>
#include<graphics.h>
#include<hack.h>
 int main()
{
 int gm,gd=DETECT;
 int x,y,click;
 initgraph(&gd,&gm,"");
 rectangle(10,10,200,200);
 callmouse();
 restrict_mouse(1,1,getmaxx()-2,getmaxy()-2);
 while(1)
{
 mouse_status(&x,&y,&click);
      if(click!=0)
     {
	 if(click==1)
	{
	 printf("\t%d\t%d",x,y);
	}
	 else if(click==2)
	{
	 break;
	}
     }
}
 return(0);
}