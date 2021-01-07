/*
7.Write a program to cyclically rotate an array by one.
From the list of Final450
https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one/0
06-01-2021
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,iter=0,iter1=0,temp,t;
    cin>>t;
    vector<vector<int>> g1(t);
    for(iter=0;iter<t;iter++)
    {
        cin>>n;
        g1[iter]=vector<int>(n);
        for(iter1=0;iter1<n;iter1++)
        {
            cin>>temp;
            if(iter1<n-1)
                g1[iter][iter1+1]=temp;
            else if(iter1==n-1)
                g1[iter][0]=temp;
        }
    }
    for(iter=0;iter<g1.size();iter++)
    {
        for(iter1=0;iter1<g1[iter].size();iter1++)
            cout<<g1[iter][iter1]<<" ";
        cout<<"\n";
    }
}
