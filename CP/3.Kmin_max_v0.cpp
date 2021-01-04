/*
3.Find the "Kth" max and min element of an array
From the list of Final450
31-12-2020
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int array_[]={1,5,4,3,2,7,0,6};
int k_min_=array_[0];
int k_max_=array_[0];
int length=sizeof(array_)/sizeof(array_[0]);
int k=0;
int min_count=0;
int max_count=0;

k_min_max()
{
    for(int iter=1;iter<length & min_count<k & max_count<k;iter++)
    {
        if(array_[iter]<k_min_)
        {
            k_min_=array_[iter];
            min_count++;
        }
        else if(array_[iter]>k_max_)
        {
            k_max_=array_[iter];
            max_count++;
        }
        cout<<array_[iter]<<"\n";
        cout<<"Iteration :"<<iter<<"\n";
    }
    cout<<"Min count"<<min_count<<" "<<"Max count"<<max_count<<"\n";
    cout<<"\nk th Min value = "<<k_min_<<"\nk th Max value = "<<k_max_;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<"Enter k for finding k th min and max element of an array.\n";
    cin>>k;
    cout<<"Original array = \n"<<array_[0]<<"\n";
    k_min_max();
}
