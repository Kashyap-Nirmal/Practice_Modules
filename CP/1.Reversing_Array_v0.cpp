/*

1.Reversing an Array
CP examples From Sheet FINAL450
29-12-2020

*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int array_[]={1,2,3,4,5};

reverse_array()
{
    int length=sizeof(array_)/sizeof(array_[0]);
    int reverse_array[length];
    for(int iter=0;iter<length;iter++)
    {
        reverse_array[length-iter-1]=array_[iter];
    }
    for(int iter=0;iter<length;iter++)
    {
        cout<<reverse_array[iter]<<" ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<"Original array:\n";
    int length=sizeof(array_)/sizeof(array_[0]);
    for(int iter=0;iter<length;iter++)
    {
        cout<<array_[iter]<<" ";
    }
    cout<<"\n";
    cout<<"Reversed array:\n";
    reverse_array();
}
