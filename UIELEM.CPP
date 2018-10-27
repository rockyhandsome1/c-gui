#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
void cWindow();
void button(int,int,int,int);
int main(void)
{
 //initializing the graphics
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"..//bgi");
 cWindow();
 button(10,10,100,400);
 getch();
 closegraph();
 return 0;
}
void cWindow()
{
 setcolor(GREEN);
 rectangle(0,0,getmaxx(),getmaxy());
}
void button(int l,int t,int r,int b)
{char text[20]="button";
 int hlen=(strlen(text))/2;
 rectangle(l,t,r,b);
 int x1=((r-l)-(hlen*10))/2;
 int y1=(b+t)/2;
 outtextxy(x1,y1,text);
 //printf("%d\t%d",x1,(b+t)/2);
}