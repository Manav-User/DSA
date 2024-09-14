#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *prev;
}*start=nullptr;

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
    while(ptr->next!=nullptr)
    {
        cout<<ptr->data<<"-->";
        ptr=ptr->next;
    }
    cout<<ptr->data<<endl;
    while(ptr->prev!=nullptr)
    {
        cout<<ptr->data<<"-->";
        ptr=ptr->prev;
    }
    cout<<ptr->data<<endl;
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

void insertAtSP()
{
    int x,d;
    cout<<"Enter data: ";
    cin>>x;
    cout<<"Enter data(key) after which u want to insert data: ";
    cin>>d;
    Node *newnode=new Node;
    newnode->data=x;
    newnode->next=nullptr;
    newnode->prev=nullptr;
    Node *ptr=start;
    while(ptr->next!=nullptr)
    {
        if(ptr->data==d)
        {
            newnode->next=ptr->next;
            newnode->prev=ptr;
            ptr->next->prev=newnode;
            ptr->next=newnode;
            cout<<"Node is inserted at specific position."<<endl;
            break;
        }
        ptr=ptr->next;
    }
}

void deleteFrontSLL()
{
    if(start==nullptr)
    {
        cout<<"List is empty, nothing to delete."<<endl;
    }
    Node *ptr=start;
    start=start->next;
    delete ptr;
    cout<<"Data is deleted from first.\n";
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

void deleteNode()
{
    if(start==nullptr){
        cout<<"-----UNDERFLOW-----"<<endl;
        return;
    }
    int d;
    cout<<"Enter data of node which u want to delete:";
    cin>>d;
    Node *ptr=start;
    Node *preptr=start;
    if(d==start->data){
        start=start->next;
    }
    else{
        while(ptr->next!=nullptr)
        {
            if(ptr->data==d)
            {
                preptr->next=ptr->next;
                ptr->next->prev=preptr;
                break;
            }
            preptr=ptr;
            ptr=ptr->next;
        }
    }
    delete ptr;
    cout<<"Node is deleted."<<endl;
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
        cout<<"5) Insert at specific position in Doubly Link List\n";
        cout<<"6) Delete from front in Doubly Link List\n";
        cout<<"7) Delete from last in Doubly Link List\n";
        cout<<"8) Delete from specific position in Doubly Link List\n";
        cout<<"9) Exit \n";
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
                insertAtSP();
                break;
            case 6:
                deleteFrontDLL();
                break;
            case 7:
                deleteLastDLL();
                break;
            case 8:
                deleteNode();
                break;
        }
    }while(n!=9);
    return 0;
}
