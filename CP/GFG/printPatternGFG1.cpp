/*
    https://practice.geeksforgeeks.org/problems/print-the-pattern-set-1/1
    Submitted
	05-01-2021
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void printPatternGFG(int n)
{
    int iter=0,iter1=0,iter2=0,output=n;
    for(iter=n;iter>0;iter--)
    {
        output=n;
        for(iter1=n*iter;iter1>0;iter1--)
        {
            cout<<output<<" ";
            if(iter1%iter==1 | iter==1)
                output--;
        }
        cout<<"$";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    printPatternGFG(n);
}
