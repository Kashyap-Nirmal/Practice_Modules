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
        LL * next;
        void insertm(int);
        void display();
        LL(){
            next=NULL;
            data=0;
        }
};
LL *temp=NULL,*head=NULL;
void LL::display(){
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void LL::insertm(int m)
{
    if(head==NULL)
    {
        head=new LL;
        head->data=m;
    }
    else
    {
        LL *new1;
        temp=head;
        new1=new LL;
        new1->data=m;
        while(m>temp->next->data)
        {
            if(temp->next->next!=NULL)
                /*For avoiding temp->next->data i.e. for last
                element if it shifts temp then temp->next->data
                will generate error bcoz temp->next==NULL
                */
                temp=temp->next;
            else
                break;
        }
        if(temp->next->next==NULL)
        {
            //For insert at end i.e. after checking asc. order
            if(m>temp->next->data)
                temp->next->next=new1;
            else
            {
                new1->next=temp->next;
                temp->next=new1;
            }
        }
    }
}
int main()
{
    for(int i=1;i<11;i++)
    {
        if(i==1){
            temp=new LL;
            temp->data=i;
            head=temp;
        }
        else if(i!=3 && i!=8)
        {
            temp->next=new LL;
            temp=temp->next;
            temp->data=i;
        }
    }
    cout<<"Before insertion:"<<endl;
    temp->display();
    cout<<endl<<"Inserting 3:"<<endl;
    temp->insertm(3);
    temp->display();
    cout<<endl<<"Inserting 8:"<<endl;
    temp->insertm(8);
    temp->display();
    cout<<endl<<"Inserting 11:"<<endl;
    temp->insertm(11);
    temp->display();
}
