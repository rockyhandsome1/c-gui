#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
union REGS i,o;  // 2 structs wordregs and byteregs //dos.h
void printxy();
void main()
{
	clrscr();
	i.x.ax=0; //asssigned value to the union var for checking mouse status
	int86(0x33,&i,&o);//calling an interrupt
	if(o.x.ax==0)
	  printf("\nmouse mot available\n");
	else      //standard return value (hexcode is) FFFFH
	  printf("\nmouse available\n");
	i.x.ax=1;   //displays mouse on the screen
	printf("\nmouse is put to work\n");
	int86(0x33,&i,&o);//calling interrupt again
	//accessing the position
	printxy();
	getch();
}

void printxy()
{
  while(!kbhit())
  {
     i.x.ax=3;//to get the position
     int86(0x33,&i,&o);
     printf("X:%d",o.x.cx);
     printf("\nY:%d",o.x.dx);
     delay(10);
     clrscr();
  }
}
