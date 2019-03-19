/*
Here linked list has static inputs 1 to 10 in asc. order.Also
avoiding 3 and 8 as per the requirement
*/
#include<iostream>
using namespace std;
class LL
{
    public:
        int data;
        LL * next,*pre;
        void insertfront(int);
        void insertend(int);
        void insertm(int);
        void display(LL *);
        void deletefront();
        void deleteend();
        void deletem(int);
        LL(){
            next=NULL;
            pre=NULL;
            data=0;
        }
};
LL *temp=NULL,*left1=NULL,*right1=NULL;
/*
Writing only left and right somehow created error while using
them without :: i.e. scope for global variable in further uses
But replacing with left1 and right1 solves it.IDK why???
*/
void LL::display(LL *temp=left1){
    if(temp->next!=NULL)
    {
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl<<endl;
    }
    else
    {
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->pre;
        }
        cout<<endl<<endl;
    }
}
void LL::insertfront(int m)
{
    //Left is entered in temp
    temp=left1;
    temp->pre=new LL;
    temp->pre->next=temp;
    temp=temp->pre;
    temp->data=m;
    left1=temp;
}
void LL::insertend(int m)
{
    //Right is entered in temp
    temp=right1;
    temp->next=new LL;
    temp->next->pre=temp;
    temp=temp->next;
    temp->data=m;
    right1=temp;
}
void LL::insertm(int m)
{
    if(left1==NULL)
    {
        left1=new LL;
        left1->data=m;
        left1->pre=NULL;
        left1->next=NULL;
    }
    else
    {
        LL *t,*new1,*temp=left1;
        new1=new LL;
        new1->data=m;
        new1->pre=NULL;
        new1->next=NULL;
        while(m>temp->data)
        {
            temp=temp->next;
        }
        if(temp->next!=NULL){
            temp=temp->pre;
            new1->next=temp->next;
            new1->pre=temp;
            temp->next=new1;
        }
        else{
            temp=temp->pre;
            new1->next=NULL;
            temp->next=new1;
        }
    }
}
void LL::deletefront()
{
    //Left1 is entered in temp
    temp=left1;
    left1=temp->next;
    temp->next->pre=NULL;
    if(left1==NULL)
        cout<<"Empty linked list."<<endl;
}
void LL::deleteend()
{
    //Right1 is entered in temp
    temp=right1;
    right1=temp->pre;
    temp->pre->next=NULL;
    if(right1==NULL)
        cout<<"Empty linked list."<<endl;
}
void LL::deletem(int m)
{
    if(left1->data==m)
    {
        left1->pre=NULL;
        left1->next=NULL;
        cout<<" Empty linked list"<<endl;
    }
    else
    {
        LL *temp=left1;
        while(m!=temp->data)
        {
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"Node not found."<<endl;
        }
        temp->pre->next=temp->next;
        temp->next->pre=temp->pre;
    }
}
int main()
{
    for(int i=1;i<11;i++)
    {
        if(i==1){
            temp=new LL;
            temp->data=i;
            left1=temp;
        }
        else if(i!=3 && i!=8)
        {
            temp->next=new LL;
            temp->next->pre=temp;
            temp=temp->next;
            temp->data=i;
        }
    }
    right1=temp;
    cout<<"Before insertion:"<<endl;
    temp->display();
    cout<<"After insertion of 0 at front:"<<endl;
    temp->insertfront(0);
    temp->display();
    cout<<"After deletion of 0 from front:"<<endl;
    temp->deletefront();
    temp->display();
    cout<<"After insertion of 11 at end:"<<endl;
    temp->insertend(11);
    temp->display();
    cout<<"After deletion of 11 from end:"<<endl;
    temp->deleteend();
    temp->display();
    cout<<"Inserting 3:"<<endl;
    temp->insertm(3);
    temp->display();
    cout<<"Deleting 3:"<<endl;
    temp->deletem(3);
    temp->display();
    cout<<"Reverse traversal"<<endl;
    temp->display(right1);
}
