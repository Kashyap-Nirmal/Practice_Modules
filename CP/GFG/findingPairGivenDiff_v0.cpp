/*
Find pair given difference.
https://practice.geeksforgeeks.org/problems/find-pair-given-difference/0
Submitted
08-01-2021
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,l,n,iter,iter2,t1;
    cin>>t;
    int flag[t];
    while(t--)
    {
        cin>>l;
        cin>>n;
        t1=t;
        int arr[l];
        for(iter=0;iter<l;iter++)
            cin>>arr[iter];
        flag[t]=-1;
        for(iter=0;flag[t]!=1 && iter<l;iter++)
            for(iter2=iter+1;flag[t]!=1 && iter2<l;iter2++)
            {
                /*
                    Check if the needed difference added with any element of array forms
                    any other element of array.
                    I.E. if Desired difference = 2
                    Now with one of the input element we can search for other element.
                    i.e. A-B=C. We have A/B as array element,
                    C is input by the user.
                    Thus, we are searching for B/A.
                */
                if(arr[iter]==n+arr[iter2] | arr[iter2]==n+arr[iter])
                    flag[t]=1;
            }
    }
    while(t1--)
        cout<<flag[t1]<<"\n";
}
