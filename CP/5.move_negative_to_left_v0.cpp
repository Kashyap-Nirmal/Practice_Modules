/*
5.Move all the negative elements to one side of the array
From the list of Final450
04-01-2021
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int iter=0;

move_negative_to_left(int size_)
{
    /*
        Logic:
        -ve numbers are inserted from left end. i.e. grows to right
        +ve numbers are inserted from right end. i.e. grows to left
    */
    int array_[size_];
    int count_negative=0,count_positive=size_-1;
    int desired_array_[size_];
    cout<<"Enter "<<size_<<" inputs in terms of 0,1,2 for the array.\n";
    for(iter=0;iter<size_;iter++)
    {
        cin>>array_[iter];
        if(array_[iter]<0)
        {
            desired_array_[count_negative]=array_[iter];
            count_negative++;
        }
        else if(array_[iter]>=0)
        {
            desired_array_[count_positive]=array_[iter];
            count_positive--;
        }
    }
    for(iter=0;iter<size_;iter++)
    {
        cout<<desired_array_[iter]<<" ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int size_;
    cout<<"Enter size of the array.\n"; //Not executed after adding Fast I/O
    cin>>size_;
    move_negative_to_left(size_);
}
