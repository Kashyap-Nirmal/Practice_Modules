//Binary search recursive
#include<iostream>
using namespace std;
int adhar[20]={89891235,89891236,89891237,89891238,89891239,89891240,89891241,89891242,89891243,
    89891244,89891245,89891246,89891247,89891248,89891249,89891250,89891251,89891252,89891253,89891254}
    ,k,i=0,f=0,j=19;
int search()
{
        if(adhar[(j+i)/2]==k)
        {
            cout<<(j+i)/2<<" is the index for your key.";
            f=1;
        }
        else
        {
            if(i!=j)
            {
                if(k<adhar[(i+j)/2])
                    j=(i+j)/2;
                else
                    i=(j+i)/2;
                search();
            }
            else
            {
                cout<<"No match found.";
                return 1;
            }
        }
}
int main()
{
    cout<<"Enter search key :";
    cin>>k;
    search();
}
