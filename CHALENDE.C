#include<stdio.h>
#include<conio.h>
 char day_name[8][5]={"","MON","TUE","WED","THR","FRI","SAT","SUN"};
 int months[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
 int leep_year(long int year)
{
	 if(year%100==0)
	{
		if(year%400==0)
		return(1);
		else
		return(0);
	}
	 else if(year%4==0)
	 return(1);
	 else
	 return(0);
}
 int getday(long int year,int mont,int date)
{
 int day=1,temp_month=1,nod=0;
 long int temp_year=1;
	if(leep_year(year))
	months[2]=29;
	while(temp_year<year)
       {
		if(leep_year(temp_year)==1)
		day+=2;
		else
		++day;
	++temp_year;
		if(day==8)
		day=1;
		else if(day==9)
		day=2;
       }
	while(temp_month<mont)
       {
	nod+=months[temp_month];
	++temp_month;
       }
 nod+=date-1;
 day+=nod%7;
	if(day==8)
	day=1;
	else if(day==9)
	day=2;
 return(day);
}
 void main()
{
 long int year;
 int month;
 int day,date=1;
 int x=2,y=6,i=1,j=1;
 clrscr();
 gotoxy(35,2);		printf("CALENDER");
 gotoxy(33,3);		printf("------------");
 gotoxy(2,4);		printf("YEAR-");
 gotoxy(40,4);		printf("MONTH-");
 gotoxy(8,4);          scanf("%ld",&year);
 gotoxy(48,4);          scanf("%d",&month);
	while(i<=7)
       {
	gotoxy(x,y);	printf("%s",day_name[i]);
	++i;
	x+=5;
       }
 x=2; 	y=7;
 x=x+(getday(year,month,date)-2)*5;
	 while(date<=months[month])
	{
	 x=x+5;
		 if(x>33)
		{
		 x=2;
		 ++y;
		}
	  gotoxy(x,y);
	  printf("%d",date);
	 ++date;
	}
 getch();
}