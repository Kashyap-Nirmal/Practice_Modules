#include<iostream>
using namespace std;
#define max 5
int flag=0;
/*
    flag is used for convenience with overflow,underflow etc conditions.Here,
    flag=0 means default condition.
    flag=1 means overflow condition.
    flag=2 means underflow condition.
*/
class crqueue
{
    public:
    int Q[max]={0},front=-1,rear=-1;
    void cqinsert(int x)
    {
        if(front==rear && front==-1)//Here we need to set front=rear=0 initially
        {
            front=0;
            rear=0;
            Q[rear]=x;
        }
        else if(rear==max-1 && front!=0)//Rear reached limit,space is available at front
        {
            rear=0;
            Q[rear]=x;
        }
        /*Normal scenario excluding 1st insertion or reaching max limit for rear*/
        else if(front!=-1 && rear!=front-1)
        {
            rear++;
            Q[rear]=x;
        }
        else if(rear==front-1 && front!=0)//Overflow
        {
            flag=1;
        }
        else if(front==0 && rear==max-1)//Overflow
        {
            flag=1;
        }
        display();
    }
    void cqdelete()
    {
        if(flag!=2)//For reseting flag to 0 for the delete operations here.
            flag=0;
        if(front!=rear && front<max-1)
        {
            Q[front]=0;
            front++;
        }
        else if(front==max-1 && rear!=0)//If insertion is there and rear!=0
        {
            Q[front]=0;
            front=0;
        }
        else if(front==max-1)//rear==0  i.e. Second last present element is deleted.
        {
            Q[front]=0;
            front=0;
        }
        else if(front==rear && front!=-1)//Last element present is deleted
        {
            Q[front]=0;
            front=-1;
            rear=-1;
        }
        else if(front==rear&&front==-1||front==max-1&&rear==0||rear==front-1)//Underflow
        {
            flag=2;
        }
        display();
    }
    void display()
    {
         if(flag==1)
            cout<<"Overflow"<<endl;
        else if(flag==2)
            cout<<"Underflow";
        for(int i=0;front!=-1 && i<max;i++)//Non empty queue upto max limit
        {
            cout<<Q[i]<<" ";
        }
        if(front==-1 && flag!=2)//For overflow no need to display empty
            cout<<"Empty";
        cout<<endl<<"F = "<<front<<" R ="<<rear;
        cout<<endl;
    }
};
int main()
{
    crqueue cr;
    cout<<"Assumption:Here 0 means data is either deleted or not inserted."<<endl<<endl;
    cout<<"I 10"<<endl;
    cr.cqinsert(10);
    cout<<endl<<"I 50"<<endl;
    cr.cqinsert(50);
    cout<<endl<<"I 40"<<endl;
    cr.cqinsert(40);
    cout<<endl<<"I 80"<<endl;
    cr.cqinsert(80);
    cout<<endl<<"d 10"<<endl;
    cr.cqdelete();
    cout<<endl<<"I 200"<<endl;
    cr.cqinsert(200);
    cout<<endl<<"I 70"<<endl;
    cr.cqinsert(70);
    cout<<endl<<"I 150"<<endl;
    cr.cqinsert(150);
    cout<<endl<<"d 50"<<endl;
    cr.cqdelete();
    cout<<endl<<"d 40"<<endl;
    cr.cqdelete();
    cout<<endl<<"d 80"<<endl;
    cr.cqdelete();
    cout<<endl<<"d 200"<<endl;
    cr.cqdelete();
    cout<<endl<<"d 70"<<endl;
    cr.cqdelete();
    cout<<endl<<"d"<<endl;
    cr.cqdelete();
}
