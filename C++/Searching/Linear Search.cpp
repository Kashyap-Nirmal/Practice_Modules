//Linear search
#include<iostream>
using namespace std;
int main()
{
    int adhar[15]={2,9,7,6,12,67,8,90,15,33,78,88,133,24,5},k,i;
    cout<<"Enter search key :";
    cin>>k;
    for(i=0;i<15;i++)
    {
        if(adhar[i]==k)
        {
            cout<<i<<" is the index for your key.";
            return 0;
        }
    }
    cout<<"No match found.";
}
