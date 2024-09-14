#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
}*start=nullptr;


void createCSLL()
{
    int data;
    cout<<"\nEnter a data here(or -1 for EXIT): ";
    cin>>data;
    while(data!=-1)
    {
        Node *newnode=new Node;
        Node *ptr;
        newnode->data=data;
        newnode->next=nullptr;
        if(start==nullptr)
        {
            start=newnode;
            newnode->next=start;
        }
        else
        {
            ptr=start;
            while(ptr->next!=start)
            {
                ptr=ptr->next;
            }
            ptr->next=newnode;
            newnode->next=start;
        }
        cout<<"\nEnter a data here(or -1 for EXIT): ";
        cin>>data;
    }
    cout<<"Circular Single LinkList Created.\n";
}

void displayCSLL()
{
    if(start==nullptr)
    {
        cout<<"List is empty, nothing to print."<<endl;
    }
    Node *ptr=start;
    while(ptr->next!=start)
    {
        cout<<ptr->data<<"-->";
        ptr=ptr->next;
    }
    cout<<ptr->data<<endl;
    cout<<"After last element, next element is "<<ptr->next->data<<endl;
}

void enterFrontCSLL()
{
    int data;
    cout<<"\nEnter a data here:";
    cin>>data;
    Node *newnode=new Node;
    newnode->data=data;
    newnode->next=nullptr;
    if(start==nullptr)
    {
        start=newnode;
        newnode->next=start;
    }
    else
    {
        Node *ptr=start;
        while(ptr->next!=start)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
        newnode->next=start;
        start=newnode;
    }
    cout<<"Data is entered from front.\n";
}

void enterLastCSLL()
{
    int data;
    cout<<"\nEnter a data here:";
    cin>>data;
    Node *newnode=new Node;
    newnode->data=data;
    newnode->next=nullptr;
    if(start==nullptr)
    {
        start=newnode;
        newnode->next=start;
    }
    else
    {
        Node *ptr=start;
        while(ptr->next!=start)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
        newnode->next=start;
    }
    cout<<"Data is entered from last.\n";
}

void deleteFrontCSLL()
{
     if(start==nullptr)
    {
        cout<<"List is empty, nothing to delete."<<endl;
    }
    Node *ptr=start;
    while(ptr->next!=start)
    {
        ptr=ptr->next;
    }
    Node *temp=start;
    start=start->next;
    ptr->next=start;
    delete temp;
    cout<<"Data is deleted from front.\n";
}

void deleteLastCSLL()
{
     if(start==nullptr)
    {
        cout<<"List is empty, nothing to delete."<<endl;
    }
    Node *ptr,*preptr;
    ptr=start;
    while(ptr->next!=start)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=start;
    delete ptr;
    cout<<"Data is deleted from last.\n";
}



int main()
{
    int n;
    do{
        cout<<"\n\nChoose from the following:\n";
        cout<<"1) Create Circular Single Link List\n";
        cout<<"2) Print Circular Single Link List\n";
        cout<<"3) Insert from front in Circular Single Link List\n";
        cout<<"4) Insert from last in Circular Single Link List\n";
        cout<<"5) Delete from first in Circular Single Link List\n";
        cout<<"6) Delete from last in Circular Single Link List\n";
        cout<<"7) Exit \n";
        cout<<"Enter your option number: ";
        cin>>n;
        switch(n)
        {
            case 1:
                createCSLL();
                break;
            case 2:
                displayCSLL();
                break;
            case 3:
                enterFrontCSLL();
                break;
            case 4:
                enterLastCSLL();
                break;
            case 5:
                deleteFrontCSLL();
                break;
            case 6:
                deleteLastCSLL();
                break;
        }
    }while(n!=7);
    return 0;
}
