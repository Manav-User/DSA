#include<iostream>
using namespace std;
struct TreeNode{
    int data;
    TreeNode *right;
    TreeNode *left;
}*root=nullptr;
TreeNode *create()
{
    int data;
    cin>>data;
    TreeNode *newnode=new TreeNode;
    newnode->data=data;
    if(data==-1)
    {
        return nullptr;
    }
    cout<<"Enter left child of "<<data<<":";
    newnode->left=create();
    cout<<"Enter right child of "<<data<<":";
    newnode->right=create();
    return newnode;
}
void Inorder(TreeNode *ptr)
{
    if(ptr==nullptr)
    {
        return;
    }
    Inorder(ptr->left);
    cout<<ptr->data<<" ";
    Inorder(ptr->right);
}
void Preorder(TreeNode *ptr)
{
    if(ptr==nullptr)
    {
        return;
    }
    cout<<ptr->data<<" ";
    Inorder(ptr->left);
    Inorder(ptr->right);
}
void Postorder(TreeNode *ptr)
{
    if(ptr==nullptr)
    {
        return;
    }
    Inorder(ptr->left);
    Inorder(ptr->right);
    cout<<ptr->data<<" ";
}



int main()
{
    int n;
    TreeNode *root;
    do{
        cout<<"\n\nChoose from the following:\n";
        cout<<"1) Creating \n";
        cout<<"2) InOrder traversing \n";
        cout<<"3) PreOrder traversing\n";
        cout<<"4) PostOrder traversing\n";
        cout<<"4) Exit \n";
        cout<<"Enter option number: ";
        cin>>n;
        switch(n)
        {
            case 1:
                root=create();
                cout<<"Tree is created!!!!"<<endl;
                break;
            case 2:
                Inorder(root);
                break;
            case 3:
                Preorder(root);
                break;
            case 4:
                Postorder(root);
                break;
        }
    }while(n!=5);
    return 0;
}
