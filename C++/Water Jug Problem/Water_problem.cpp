/*
->This is the program for water jug problem.
->Here the capacity of the two jugs is taken predefined i.e 4 and 3 litres.
->The algorithm followed in this code was derived by observing limited number
of test cases so it may not be generalized.
*/
#include<iostream>
#define a 4
#define b 3
using namespace std;
int i=0,c[50]={0},d[50]={0};
void display(int n)
{
    cout<<"F("<<c[n]<<","<<d[n]<<") n = "<<n<<endl;
}
int calculate()
{
    i=1;
    display(i);
    for(int k=0;c[i]==2 || k<50;k++)
    {
        if(d[i]==0)
        {
            i++;
            d[i]=b;
            c[i]+=c[i-1];
            display(i);
        }
        else if(c[i]<a && d[i]!=0)
        {
            i++;
            c[i]=c[i-1]+d[i-1];
            d[i]=0;
            if(c[i]>a)
            {
                d[i]=c[i]-a;
                c[i]=a;
                display(i);
            }
            else
            {
                display(i);
            }
        }
        else if(d[i]==2)
        {
            i++;
            d[i]+=d[i-1];
            display(i);
            i++;
            c[i]=d[i-1];
            d[i]+=0;
            display(i);
            return 0;
        }
    }
}
int main()
{
    cout<<"F(4,3) : "<<endl<<endl;
    calculate();
}
