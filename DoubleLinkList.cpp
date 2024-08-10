#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *prev;
}*start=nullptr;

//Double Link List

void createDLL()
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
        }
        else
        {
            Node *ptr=start;
            while(ptr->next!=nullptr)
            {
                ptr=ptr->next;
            }
            ptr->next=newnode;
            newnode->prev=ptr;
        }
        cout<<"\nEnter a data here(or -1 for EXIT): ";
        cin>>data;
    }
    cout<<"Doubly LinkList Created.\n";
}
void displayDLL()
{
    if(start==nullptr)
    {
        cout<<"List is empty, nothing to print."<<endl;
    }
    Node *ptr=start;
    while(ptr!=nullptr)
    {
        cout<<ptr->data<<"-->";
        ptr=ptr->next;
    }
    //cout<<endl<<ptr->prev->data<<endl;
}
void insertFrontDLL()
{
    int data;
    cout<<"\nEnter a data: ";
    cin>>data;
    Node *newnode=new Node;
    newnode->data=data;
    newnode->next=start;
    start->prev=newnode;
    newnode->prev=nullptr;
    start=newnode;
    cout<<"Data is entered from front.\n";
}
void insertLastDLL()
{
    int data;
    cout<<"\nEnter a data: ";
    cin>>data;
    Node *newnode=new Node;
    newnode->data=data;
    newnode->next=nullptr;
    newnode->prev=nullptr;
    if(start==nullptr)
    {
        start=newnode;
    }
    else
    {
        Node *ptr=start;
        while(ptr->next!=nullptr)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
        newnode->prev=ptr;
    }
    cout<<"Data is entered from last.\n";
}
void deleteFrontDLL()
{
    if(start==nullptr)
    {
        cout<<"List is empty, nothing to delete."<<endl;
    }
    Node *ptr=start;
    start=start->next;
    start->prev=nullptr;
    delete ptr;
    cout<<"Data is deleted from first.\n";
}
void deleteLastDLL()
{
    if(start==nullptr)
    {
        cout<<"List is empty, nothing to delete."<<endl;
    }
    Node *ptr=start;
    while(ptr->next!=nullptr)
    {
        ptr=ptr->next;
    }
    ptr->prev->next=nullptr;
    delete ptr;
    cout<<"Data is deleted from last.\n";
}

//Circular Doubly Link List

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
    cout<<"After last element->"<<ptr->next->data<<endl;
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
        cout<<"1) Create Doubly Link List\n";
        cout<<"2) Print Doubly Link List\n";
        cout<<"3) Insert from front in Doubly Link List\n";
        cout<<"4) Insert from last in Doubly Link List\n";
        cout<<"5) Delete from front in Doubly Link List\n";
        cout<<"6) Delete from last in Doubly Link List\n";
        cout<<"7) Create Circular Doubly Link List\n";
        cout<<"8) Print Circular Doubly Link List\n";
        cout<<"9) Insert from front in Circular Doubly Link List\n";
        cout<<"10) Insert from last in Circular Doubly Link List\n";
        cout<<"11) Delete from first in Circular Doubly Link List\n";
        cout<<"12) Delete from last in Circular Doubly Link List\n";
        cout<<"13) Exit \n";
        cout<<"Enter your option number: ";
        cin>>n;
        switch(n)
        {
            case 1:
                createDLL();
                break;
            case 2:
                displayDLL();
                break;
            case 3:
                insertFrontDLL();
                break;
            case 4:
                insertLastDLL();
                break;
            case 5:
                deleteFrontDLL();
                break;
            case 6:
                deleteLastDLL();
                break;
            case 7:
                createCDLL();
                break;
            case 8:
                displayCDLL();
                break;
            case 9:
                insertFrontCDLL();
                break;
            case 10:
                insertLastCDLL();
                break;
            case 11:
                deleteFrontCDLL();
                break;
            case 12:
                deleteLastCDLL();
                break;
        }
    }while(n!=13);
    return 0;
}

