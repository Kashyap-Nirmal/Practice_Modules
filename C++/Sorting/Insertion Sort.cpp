//Insertion sort
#include<iostream>
using namespace std;
double a[]={7.4,2.3,5.1,5.4,7.3,2.1,6.4,1.1,4.4,5.2,6.3,7.1,2.2,1.2,3.1,3.3,2.4,6.2,1.3,3.2,1.4,7.2,4.1,3.4,5.3,4.2,6.1,4.3},t;
int i,j,k,p=0,c=0,s=0;
void display()
{
    cout<<"Sorted array using insertion sort is:"<<endl;
    for(i=0;i<28;i++)
        cout<<a[i]<<" ";
    cout<<endl<<"The number of comparisons = "<<c<<" swaps = "<<s<<" pass = "<<p;
}
int main()
{
    for(i=1;i<28;i++)
    {
        p++;
        for(j=i;;--j)
        {
            c++;
            if(a[j]<a[j-1])
            {
                s++;
                t=a[j];
                a[j]=a[j-1];
                a[j-1]=t;
            }
            else
                break;
        }
    }
    display();
}
