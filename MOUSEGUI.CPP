#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
void main()
{
clrscr();
union REGS i,o;  // 2 structs wordregs and byteregs //dos.h
i.x.ax=0; //asssigned value to the union var for checking mouse status
int86(0x33,&i,&o);//calling an interrupt
if(o.x.ax==0)
printf("\nmouse mot available\n");
else      //standard return value (hexcode is) FFFH
printf("\nmouse available\n");
i.x.ax=1;   //displays mouse on the screen
printf("\nis it seen?\n");
int86(0x33,&i,&o);//calling interrupt again
getch();
}