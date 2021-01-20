/*
    Count squares
    https://practice.geeksforgeeks.org/problems/count-squares3649/1
    20-01-21
    Submitted
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,iter,temp=1;
    cin>>n;
    for(iter=1;temp<n;iter++)
    {
        temp=iter;
        temp*=temp;
    }
    if(iter>2 || n>2)
        cout<<iter-2;
    else
        cout<<0;
}
