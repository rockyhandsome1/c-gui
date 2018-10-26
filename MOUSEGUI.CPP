#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
union REGS i,o;  // 2 structs wordregs and byteregs //dos.h

void mStatus();     //prototypes
void mDisplay();
void xyPosition();
void clickcheck();
void hideM();

void main()
{
	clrscr();
	int choice;
	do
	{       printf("Menu Options:\n");
		printf("1.check mouse status\n");
		printf("2.display mouse\n");
		printf("3.display the position of mouse\n");
		printf("4.check out mouse clicks\n");
		printf("5.hide the mouse\n");
		printf("6.exit\n");
		printf("enter your choice..\n");
		scanf("%d",&choice);
		switch (choice)
		{case 1:mStatus();break;
		 case 2:mDisplay();break;
		 case 3:xyPosition();break;
		 case 4:clickcheck();break;
		 case 5:hideM();break;
		 case 6:printf("warning:are u sure?\nPress any key to exit.");break;
		 default:printf("\nInvalid choice!");
		};
	}while(choice!=6);
	getch();
}
void mStatus()
{
	i.x.ax=0; //asssigned value to the union var for checking mouse status
	int86(0x33,&i,&o);//calling an interrupt
	if(o.x.ax==0)
	  printf("mouse is not available\n\n");
	else      //standard return value (hexcode is) FFFFH
	  printf("mouse available\n\n");
}

void mDisplay()
{
	i.x.ax=1;   //displays mouse on the screen
	int86(0x33,&i,&o);//calling interrupt again
	if(o.x.ax=0)
	printf("error in displaying the mouse\n\n");
	else
	printf("mouse is displayed\n\n");
}

void xyPosition()
{ clrscr();
  i.x.ax=3;//to get the position
  while(!kbhit())
  {
     int86(0x33,&i,&o);
     gotoxy(1,1);
     printf("X:%d\tY:%d",o.x.cx,o.x.dx);
     delay(10);
  }
}
void clickcheck()
{clrscr();
 i.x.ax=3;
 while(!kbhit())
 {
   int86(0x33,&i,&o);
   gotoxy(1,1);
	 switch (o.x.bx)
	{
	 case 1:printf("\nright_click");break;
	 case 2:printf("\nleft_click_");break;
	 default:printf("\nno_click___");
	};
 }
}
void hideM()
{
 i.x.ax=2;     //initializing to 2 to hide the mouse
 int86(0x33,&i,&o);    //calling interrupt

}