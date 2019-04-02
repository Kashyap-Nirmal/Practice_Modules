//Simple timer displaying Hours,Minutes,Seconds
#include<graphics.h>
#include<iostream>
#include<stdio.h>
#include<dos.h>
using namespace std;
int main()
{
    int gd=DETECT,gm;
    int a=0,b=0,c=0,d=0,e=0,f=0;
    char m[128];
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    while(!kbhit())
    {
        sprintf(m,"%d%d:%d%d:%d%d",a,b,c,d,e,f);
        settextstyle(1,HORIZ_DIR,8);
        outtextxy(550,350,m);
        if(f==9)
        {
            f=-1;
            e++;
        }
        if(e==6)
        {
            e=0;
            d++;
        }
        if(d==10)
        {
            d=0;
            c++;
        }
        if(c==6)
        {
            c=0;
            b++;
        }
        if(b==10)
        {
            b=0;
            a++;
        }
        if(a==1)
        {
            if(b==3){
                b=0;
                a=0;
            }
            else
            {
                a=0;
                a++;
            }
        }
        delay(500);
        f++;
    }
}
