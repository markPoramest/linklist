#include<iostream>
using namespace std;
class node
{   public:
    int data;
    node *next;
};
class linklist
{   public:
    node *head;
    linklist()
    {
        head=NULL;
    }
    void insert(int data, int idx)
    {
        node *temp=new node;
        temp->data=data;
        temp->next=NULL;
        if(idx==0)
        {
            temp->next=head;
            head=temp;
        }
        else
        {
            node *temp1=head;
            for(int i=0;i<idx-1;i++)
            {
                temp1=temp1->next;
            }
            temp->next=temp1->next;
            temp1->next=temp;
        }
    }
    void display()
    {
        node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    void delete1(int id)
    {
        node *temp=head;
        if(id==0)
        {
            head=temp->next;
            delete temp;
        }
        else
        {
            for(int i=0;i<id-1;i++)
            {
                temp=temp->next;
            }
            node *temp1=temp->next;
            temp->next=temp1->next;
            delete temp1;
        }
    }
};
int maint()
{
    linklist l;
    char button;
    int data,id;
    while (button != 'E')
    {
        cin >> button;
        switch (button)
        {   case 'I':
                cin >> data;
                cin>>id;
                l.insert(data,id);
                break;
            case 'D':
                cin >> id;
                l.delete1(id);
                break;
            default:
                break;
        }
    }
    return 0;
    
}