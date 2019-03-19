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
class queue
{
    public:
    int Q[max]={0},front=-1,rear=-1;
    void qinsert(int x)
    {
        if(front==rear && front==-1)    //Here we need to set front=rear=0 initially
        {
            front=0;
            rear=0;
            Q[rear]=x;
        }
        else if(front!=-1 && rear!=max-1)//Normal scenario excluding 1st insertion
        {
            rear++;
            Q[rear]=x;
        }
        else if(rear>=max-1)             //Overflow condition
        {
            flag=1;
        }
    }
    void qdelete()
    {
        if(flag!=2)                      //For reseting flag to 0 for the delete operations here.
            flag=0;
        if(front!=rear)
        {
            front++;
        }
        else if(front==rear && front!=-1)//For the last element in queue.
        {
            front=-1;
            rear=-1;
        }
        else if(front==rear && front==-1)//The queue is in empty condition.So delete is called means underflow
            flag=2;
    }
    void display()
    {
        if(flag==1)
            cout<<"Overflow"<<endl;
        else if(flag==2)
            cout<<"Underflow"<<endl;
        for(int i=front;i<=rear && i!=-1 && i<max;i++)//Non empty queue upto max inserted or max limit
            cout<<"Q["<<i<<"] = "<<Q[i]<<" Front = "<<front<<" Rear = "<<i<<endl;
        if(front==-1 && rear==-1 && flag!=2)          //For overflow no need to display empty
            cout<<"Empty"<<endl;
        cout<<endl;
    }
};
int main()
{
    queue q;
    for(int i=1;i<7;i++)
    {
        q.qinsert(i);
        cout<<"I"<<i<<" :"<<endl;
        q.display();
    }
    for(int i=1;i<7;i++)
    {
        q.qdelete();
        cout<<"D"<<i<<" :"<<endl;
        q.display();
    }
    flag=0;                      //For reseting flag to 0 for the further operations.
}
