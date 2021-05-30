#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

     BinaryTreeNode(T data){
         this->data=data;
         left=NULL;
         right=NULL;

     }

     ~BinaryTreeNode(){
         delete left;  //note in the case when left or right or both is NULL
         delete right; //it calls delete NULL ; which do not anything nither create error
          // so it is fine
     }

};

void printTree(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        return ;
    }

    cout<<root->data<<": ";
    if(root->left!=NULL)
    {
        cout<<"L "<<root->left->data<<", ";
    }
    if(root->right!=NULL)
    {
        cout<<"R "<<root->right->data<<", ";
    }

    cout<<endl;
  
       printTree(root->left);   
       printTree(root->right);
  
}
BinaryTreeNode<int>* takeInput(){  //Input is taken in postOrder 

  int rootData;
  cout<<"Enter root Data"<<endl;
  cin>>rootData;
  if(rootData==-1)
  {
      return NULL;
  }

 BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
 root->left=takeInput();
 root->right=takeInput();
  
return root;
}
int main()
{
    // BinaryTreeNode<int>* root=new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int>* node1=new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int>* node2=new BinaryTreeNode<int>(3);
    // root->left=node1;
    // root->right=node2;

    BinaryTreeNode<int>* root=takeInput();

    printTree(root);


    delete root;// to delete the node recursively
}