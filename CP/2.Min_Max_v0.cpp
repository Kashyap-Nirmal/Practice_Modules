/*
2.Find the maximum and minimum element in an array
From the list of Final450
30-12-2020
*/

#include<iostream>
using namespace std;

int array_[]={1,5,4,3,2,7,0,6};
int min_=array_[0];
int max_=array_[0];
int length=sizeof(array_)/sizeof(array_[0]);

min_max()
{
    for(int iter=1;iter<length;iter++)
    {
        if(array_[iter]<min_)
            min_=array_[iter];
        else if(array_[iter]>max_)
            max_=array_[iter];
        cout<<array_[iter]<<" ";
    }
    cout<<"\nMin value = "<<min_<<"\nMax value = "<<max_;
}

int main()
{
    cout<<"Original array = \n"<<array_[0]<<" ";
    min_max();
}
