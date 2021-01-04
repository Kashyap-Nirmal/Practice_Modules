/*
4.Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo
From the list of Final450
04-01-2021
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int count_0=0,count_2=size_-1,count_1=0;
//Flag=1 => count_0==iter i.e. all the zeros are crossed and we need to insert 1.
int iter=0,flag;

sort_array012(int size_)
{
    /*
        Logic:

        0 is inserted from beginning. i.e. array grows to right.
        1 is added in the spaces left.
        2 is inserted from the end.  i.e. array grows to left.

    */

    int array_[size_];
    int sorted_array_[size_];
    cout<<"Enter "<<size_<<" inputs in terms of 0,1,2 for the array.\n";
    for(iter=0;iter<size_;iter++)
    {
        cin>>array_[iter];
        if(array_[iter]==0)
        {
            sorted_array_[count_0]=0;
            count_0++;
        }
        else if(array_[iter]==2)
        {
            sorted_array_[count_2]=2;
            count_2--;
        }
        else if(array_[iter]==1)
        {
            count_1++;
        }
    }
    for(iter=count_0;iter<=count_2;iter++)
        sorted_array_[iter]=1;
    cout<<"Sorted array :\n";
    for(iter=0;iter<size_;iter++)
    {
        /*
            Method-2:

        if(iter==count_0 | flag==1 && iter<=count_2)
        {
            sorted_array_[iter]=1;
            flag=1;
        }
        */
        cout<<sorted_array_[iter]<<" ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int size_;
    cout<<"Enter size of the array.\n"; //Not executed after adding Fast I/O
    cin>>size_;
    sort_array012(size_);
}
