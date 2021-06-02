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

BinaryTreeNode<int>* takeInputLevelWise()
{
    int rootData;
    cout<<"Enter root Data"<<endl;
    cin>>rootData;
    if(rootData==-1)
     {
      return NULL;
     }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    queue< BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
         BinaryTreeNode<int>*front=q.front();
         q.pop();
        cout<<"Enter left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData==-1)
        {
            front->left=NULL;
        }else{
            front->left=new BinaryTreeNode<int>(leftChildData);
            q.push(front->left);
        }

        cout<<"Enter right child of "<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData==-1)
        {
            front->right=NULL;
        }else{
            front->right=new BinaryTreeNode<int>(rightChildData);
            q.push(front->right);
        }



    }
return root;
}

void printLevelWise(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    
    queue< BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        BinaryTreeNode<int>*front=q.front();
        q.pop();
        cout<<front->data<<": ";
        if(front->left!=NULL){
        cout<<"L "<<front->left->data<<", ";
        q.push(front->left);
        }
        if(front->right!=NULL){
        cout<<"R "<<front->right->data<<", ";
         q.push(front->right);
        }

        cout<<endl;
    }
   
}
int noOfNode(BinaryTreeNode<int>* root)
{
    if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }
    int count=0;
    if(root->left!=NULL)
    {
        count+=noOfNode(root->left);

    }
    if(root->right!=NULL)
    {
        count+=noOfNode(root->right);
        
    }

    return count+1;
}

bool findAnode(BinaryTreeNode<int>* root,int Data)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==Data)
    {
        return true;
    }
    return(findAnode(root->left,Data)||findAnode(root->right,Data));

}
 int heightOfTree(BinaryTreeNode<int>* node){
        // code here 
        int max=0;
    
        int temp1=0;
        if(node->left!=NULL)
        temp1=heightOfTree(node->left);
        int temp2=0;
        if(node->right!=NULL)
        temp2=heightOfTree(node->right);
        max=(temp1>temp2)?temp1:temp2;
    
    return max+1;
    }

   

void mirrorTree(BinaryTreeNode<int> *root) {
    // Write your code here.
    if(root==NULL)
    {
        return;
    }
    
    BinaryTreeNode<int> *temp=root->left;
    root->left=root->right;
    root->right=temp;
    mirrorTree(root->left);
    mirrorTree(root->right);
    
}

int main()
{
    // BinaryTreeNode<int>* root=new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int>* node1=new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int>* node2=new BinaryTreeNode<int>(3);
    // root->left=node1;
    // root->right=node2;

   // BinaryTreeNode<int>* root=takeInput();
    BinaryTreeNode<int>* root=takeInputLevelWise();
   // printTree(root);
   printLevelWise(root);
   cout<<noOfNode(root)<<endl;
   int Data;
  // cin>>Data;
  // cout<<findAnode(root,Data)<<endl;
   cout<<heightOfTree(root)<<endl;
   mirrorTree(root);
   printLevelWise(root);
   delete root;// to delete the node recursively

    main();
}