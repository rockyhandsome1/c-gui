#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
union REGS i,o;  // 2 structs wordregs and byteregs //dos.h
//cal number of digits of x and y positions of cursor and appling backslashes
void printxy()
{
  while(!kbhit()){
     i.x.ax=3;//to get the position
     int86(0x33,&i,&o);
     int x=o.x.cx;
     int y=o.x.dx;
     int a=x,b=y;
     int xd=0,yd=0;
  while(x!=0)
  {
   x/=10;
   ++xd;
  }
  while(y!=0)
  {
   y/=10;
   ++yd;
  }
  printf("X:%d",a);
  for(int m=0;m<xd;m++)
  printf("\b");
  if(a==0)
  printf("\b\b\b\b");
  else
  printf("\b\b");
 // printf("Y:%d",b);
 // for(int n=0;n<yd;n++)
  //printf("\b");
  delay(10);
  }
  /*
  printf("\nX:");
  printf("%d",x);
  delay(10);
  for(int i=0;i<=xd;i++)
  printf("\b");
  printf("\tY:");
  printf("%d",x);
  delay(10);
  for(int j=0;j<=yd;j++)
  printf("\b");*/
}
void main()
{
clrscr();
i.x.ax=0; //asssigned value to the union var for checking mouse status
int86(0x33,&i,&o);//calling an interrupt
if(o.x.ax==0)
printf("\nmouse mot available\n");
else      //standard return value (hexcode is) FFFH
printf("\nmouse available\n");
i.x.ax=1;   //displays mouse on the screen
printf("\nmouse is put to work\n");
int86(0x33,&i,&o);//calling interrupt again
//accessing the position
printxy();
getch();
}