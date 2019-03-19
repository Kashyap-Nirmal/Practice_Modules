//Selection sort
#include<iostream>
using namespace std;
int main()
{
    double a[]={5,4,3,2,1},t;
    //double a[]={7.4,2.3,5.1,5.4,7.3,2.1,6.4,1.1,4.4,5.2,6.3,7.1,2.2,1.2,3.1,3.3,2.4,6.2,
    //1.3,3.2,1.4,7.2,4.1,3.4,5.3,4.2,6.1,4.3},t;
    int i,j,p=0,c=0,s=0,m=0;
    for(i=0;i<4;i++)
    {
        p++;
        for(j=i+1;j<4;j++)
        {
            c++;
            if(a[m]>a[j])
            {
                m=j;
                s++;
            }
        }
        t=a[i];
        a[i]=a[m];
        a[m]=t;
    }
    cout<<"Sorted array is "<<endl;
    for(i=0;i<5;i++)
        cout<<a[i]<<endl;
    cout<<"c = "<<c<<" s = "<<s<<" p = "<<p;
}
