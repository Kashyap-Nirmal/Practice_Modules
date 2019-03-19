//Binary search iterative
#include<iostream>
using namespace std;
int adhar[20]={89891235,89891236,89891237,89891238,89891239,89891240,89891241,89891242,89891243,
    89891244,89891245,89891246,89891247,89891248,89891249,89891250,89891251,89891252,89891253,89891254}
    ,k,i=0,f=0,j=19;
int main()
{
    cout<<"Enter search key :";
    cin>>k;
    while(i!=j & i!=18)
    {
        f=(i+j)/2;
        if(adhar[f]==k)
        {
            cout<<f<<" is the index for your key.";
            return 0;
        }
        else
        {
            if(k<adhar[f])
                j=f;
            else
                i=f;
        }
    }
    if(adhar[j]==k)
    {
        cout<<j<<" is the index for your key.";
        return 0;
    }
    cout<<"No match found.";
}
