#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
}*start=nullptr;

//Single Link List

void createSLL()
{
    int data;
    cout<<"\nEnter a data here(or -1 for EXIT): ";
    cin>>data;
    while(data!=-1)
    {
        Node *newnode,*ptr;
        newnode=new Node;
        newnode->data=data;
        newnode->next=nullptr;
        if(start==nullptr)
        {
            start=newnode;
        }
        else
        {
            ptr=start;
            while(ptr->next!=nullptr)
            {
                ptr=ptr->next;
            }
            ptr->next=newnode;
        }
        cout<<"\nEnter a data here(or -1 for EXIT): ";
        cin>>data;
    }
    cout<<"Single LinkList Created.\n";
}
void displaySLL()
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
}
void enterFrontSLL()
{
    int data;
    cout<<"\nEnter a data here:";
    cin>>data;
    Node *newnode=new Node;
    newnode->data=data;
    newnode->next=start;
    start=newnode;
    cout<<"Data is entered from front.\n";
}
void enterLastSLL()
{
    int data;
    Node *newnode=new Node;
    Node *ptr;
    cout<<"\nEnter a data here:";
    cin>>data;
    newnode->data=data;
    newnode->next=nullptr;
    if(start==nullptr)
    {
        start=newnode;
    }
    else
    {
        ptr=start;
        while(ptr->next!=nullptr)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
    }
    cout<<"Data is entered from last.\n";
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
void deleteLastSLL()
{
    if(start==nullptr)
    {
        cout<<"List is empty, nothing to delete."<<endl;
    }
    Node *ptr=start;
    Node *preptr;
    while(ptr->next!=nullptr)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=nullptr;
    delete ptr;
    cout<<"Data is deleted from last.\n";
}

//Circular single Link List

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
    cout<<"After last element "<<ptr->next->data<<endl;
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

//Extra
void printReverse(Node* node)
{
    if(node==nullptr)
    {
        return;
    }
    printReverse(node->next);
    cout <<node->data<<"->";
}

void sortLL()
{
    Node *ptr;
    ptr=start;
    bool flag;
    do{
        flag=false;
        ptr=start;
        while(ptr->next!=nullptr)
        {
            if(ptr->next->data < ptr->data)
            {
                swap(ptr->data,ptr->next->data);
                flag=true;
            }
            ptr=ptr->next;
        }
    }while(flag);
    cout<<"Link list is sorted.\n";
}
int main()
{
    int n;
    do{
        cout<<"\n\nChoose from the following:\n";
        cout<<"1) Create Single Link List\n";
        cout<<"2) Print Single Link List\n";
        cout<<"3) Insert from front in Single Link List\n";
        cout<<"4) Insert from last in Single Link List\n";
        cout<<"5) Delete from front in Single Link List\n";
        cout<<"6) Delete from last in Single Link List\n";
        cout<<"7) Create Circular Single Link List\n";
        cout<<"8) Print Circular Single Link List\n";
        cout<<"9) Insert from front in Circular Single Link List\n";
        cout<<"10) Insert from last in Circular Single Link List\n";
        cout<<"11) Delete from first in Circular Single Link List\n";
        cout<<"12) Delete from last in Circular Single Link List\n";
        cout<<"13) Print Reverse \n";
        cout<<"14) Sort \n";
        cout<<"15) Exit \n";
        cout<<"Enter your option number: ";
        cin>>n;
        switch(n)
        {
            case 1:
                createSLL();
                break;
            case 2:
                displaySLL();
                break;
            case 3:
                enterFrontSLL();
                break;
            case 4:
                enterLastSLL();
                break;
            case 5:
                deleteFrontSLL();
                break;
            case 6:
                deleteLastSLL();
                break;
            case 7:
                createCSLL();
                break;
            case 8:
                displayCSLL();
                break;
            case 9:
                enterFrontCSLL();
                break;
            case 10:
                enterLastCSLL();
                break;
            case 11:
                deleteFrontCSLL();
                break;
            case 12:
                deleteLastCSLL();
                break;
            case 13:
                printReverse(start);
                break;
            case 14:
                sortLL();
                break;
        }
    }while(n!=15);
    return 0;
}
