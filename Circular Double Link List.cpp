#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *prev;
}*start=nullptr;


void createCDLL()
{
    int data;
    cout<<"\nEnter a data here(or -1 for EXIT): ";
    cin>>data;
    while(data!=-1)
    {
        Node *newnode=new Node;
        newnode->data=data;
        newnode->next=nullptr;
        newnode->prev=nullptr;
        if(start==nullptr)
        {
            start=newnode;
            newnode->next=start;
            newnode->prev=start;
        }
        else
        {
            Node *ptr=start;
            while(ptr->next!=start)
            {
                ptr=ptr->next;
            }
            ptr->next=newnode;
            newnode->prev=ptr;
            newnode->next=start;
            start->prev=newnode;
        }
        cout<<"\nEnter a data here(or -1 for EXIT): ";
        cin>>data;
    }
    cout<<"Circular Doubly LinkList Created.\n";
}

void displayCDLL()
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
    cout<<"After last element,next element is "<<ptr->next->data<<endl;
}

void insertFrontCDLL()
{
    int data;
    cout<<"\nEnter a data here:";
    cin>>data;
    Node *newnode=new Node;
    newnode->data=data;
    newnode->next=nullptr;
    newnode->prev=nullptr;
    if(start==nullptr)
    {
        start=newnode;
        newnode->next=start;
        newnode->prev=start;
    }
    else
    {
        Node *ptr=start;
        while(ptr->next!=start)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
        newnode->prev=ptr;
        newnode->next=start;
        start->prev=newnode;
        start=newnode;
    }
    cout<<"Data is entered from front.\n";
}

void insertLastCDLL()
{
    int data;
    cout<<"\nEnter a data here:";
    cin>>data;
    Node *newnode=new Node;
    newnode->data=data;
    newnode->next=nullptr;
    newnode->prev=nullptr;
    if(start==nullptr)
    {
        start=newnode;
        newnode->next=start;
        newnode->prev=start;
    }
    else
    {
        Node *ptr=start;
        while(ptr->next!=start)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
        newnode->prev=ptr;
        newnode->next=start;
        start->prev=newnode;
    }
    cout<<"Data is entered from front.\n";
}

void deleteFrontCDLL()
{
    Node *ptr=start;
    while(ptr->next!=start)
    {
        ptr=ptr->next;
    }
    start=start->next;
    start->prev=ptr;
    ptr->next=start;
    cout<<"Data is deleted from front.\n";
}

void deleteLastCDLL()
{
    Node *ptr=start;
    while(ptr->next!=start)
    {
        ptr=ptr->next;
    }
    ptr->prev->next=start;
    start->prev=ptr->prev;
    delete ptr;
    cout<<"Data is deleted from last.\n";
}



int main()
{
    int n;
    do{
        cout<<"\n\nChoose from the following:\n";
        cout<<"1) Create Circular Doubly Link List\n";
        cout<<"2) Print Circular Doubly Link List\n";
        cout<<"3) Insert from front in Circular Doubly Link List\n";
        cout<<"4) Insert from last in Circular Doubly Link List\n";
        cout<<"5) Delete from first in Circular Doubly Link List\n";
        cout<<"6) Delete from last in Circular Doubly Link List\n";
        cout<<"7) Exit \n";
        cout<<"Enter your option number: ";
        cin>>n;
        switch(n)
        {
            case 1:
                createCDLL();
                break;
            case 2:
                displayCDLL();
                break;
            case 3:
                insertFrontCDLL();
                break;
            case 4:
                insertLastCDLL();
                break;
            case 5:
                deleteFrontCDLL();
                break;
            case 6:
                deleteLastCDLL();
                break;
        }
    }while(n!=7);
    return 0;
}
