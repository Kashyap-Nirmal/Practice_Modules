/*
    Count squares
    https://practice.geeksforgeeks.org/problems/middle-of-three2926/1
    20-01-21
    Submitted
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int A,B,C;
    cin>>A;
    cin>>B;
    cin>>C;
    if(A>B)
    {
        if(A>C)
            if(B>C)
                cout<<B;
            else
                cout<<C;
        else
            cout<<A;
    }
    else
    {
        if(B>C)
            if(A>C)
                cout<<A;
            else
                cout<<C;
        else
            cout<<B;
    }
}
