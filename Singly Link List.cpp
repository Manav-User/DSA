#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
}*start=nullptr;


void createSLL()
{
    int data;
    cout<<"\nEnter a data here(or -1 for EXIT): ";
    cin>>data;
    while(data!=-1)
    {
        Node *newnode=new Node;
        newnode->data=data;
        newnode->next=nullptr;
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
    while(ptr->next!=nullptr)
    {
        cout<<ptr->data<<"-->";
        ptr=ptr->next;
    }
    cout<<ptr->data<<endl;
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
    cout<<"\nEnter a data here:";
    cin>>data;
    Node *newnode=new Node;
    newnode->data=data;
    newnode->next=nullptr;
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
    Node *ptr=start;
    while(ptr->next!=nullptr)
    {
        if(ptr->data==d)
        {
            newnode->next=ptr->next;
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
                break;
            }
            preptr=ptr;
            ptr=ptr->next;
        }
    }
    delete ptr;
    cout<<"Node is deleted."<<endl;
}

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
    Node *ptr=start;
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
        cout<<"5) Insert at specific position in Single Link List\n";
        cout<<"6) Delete from front in Single Link List\n";
        cout<<"7) Delete from last in Single Link List\n";
        cout<<"8) Delete from specific position in Single Link List\n";
        cout<<"9) Print Reverse \n";
        cout<<"10) Sort \n";
        cout<<"11) Exit \n";
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
                insertAtSP();
                break;
            case 6:
                deleteFrontSLL();
                break;
            case 7:
                deleteLastSLL(start);
                break;
            case 8:
                deleteNode();
                break;
            case 9:
                reverseNode();
                break;
            case 10:
                sortLL();
                break;
        }
    }while(n!=11);
    return 0;
}
