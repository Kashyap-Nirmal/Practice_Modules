/*
Write a program to left rotate an array by d.
https://practice.geeksforgeeks.org/problems/reversal-algorithm5340/1#
Submitted
07-01-2021
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i=0,j,n,d;
    cin>>n;
    cin>>d;
    int temp[d];
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<d;i++)
        temp[i]=arr[i];
    for(i=d;i<n;i++)
        arr[i-d]=arr[i];
    for(i=n-d,j=0;i<n;i++,j++)
        arr[i]=temp[j];
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

