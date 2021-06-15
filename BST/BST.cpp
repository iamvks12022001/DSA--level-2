#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BinarySearchTree {
    public:
    T data;
    BinarySearchTree* left;
    BinarySearchTree* right;

     BinarySearchTree(T data){
         this->data=data;
         left=NULL;
         right=NULL;

     }

     ~BinarySearchTree(){
         delete left;  //note in the case when left or right or both is NULL
         delete right; //it calls delete NULL ; which do not anything nither create error
          // so it is fine
     }

};

BinarySearchTree<int>* takeInputLevelWise()
{
    int rootData;
    cout<<"Enter root Data"<<endl;
    cin>>rootData;
    if(rootData==-1)
     {
      return NULL;
     }
    BinarySearchTree<int>* root=new BinarySearchTree<int>(rootData);
    queue< BinarySearchTree<int>*> q;
    q.push(root);
    while(!q.empty())
    {
         BinarySearchTree<int>*front=q.front();
         q.pop();
        cout<<"Enter left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData==-1)
        {
            front->left=NULL;
        }else{
            front->left=new BinarySearchTree<int>(leftChildData);
            q.push(front->left);
        }

        cout<<"Enter right child of "<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData==-1)
        {
            front->right=NULL;
        }else{
            front->right=new BinarySearchTree<int>(rightChildData);
            q.push(front->right);
        }



    }
return root;
}
int BST_search(BinarySearchTree<int>* root,int value)
{
    if(value==root->data)
    {
        return 1;
    }


    if(root->data>value &&  root->left!=NULL)
    {
        return BST_search(root->left,value);
    }
    if(root->data<value &&  root->right!=NULL)
    {
        return BST_search(root->right,value);
    }
    return 0;
}

vector<int> printRange_inBST(BinarySearchTree<int>* root,int low,int high)
{
    vector<int> vec;
    vector<int>v1;
    vector<int>v2;
    if(root==NULL)
    {
        return v1;
    }
    if(root->data>=low && root->data<=high)
    {
    vec.push_back(root->data);
    v1=printRange_inBST(root->left,low,high);
    v2=printRange_inBST(root->right,low,high);
    }

    else if(root->data>high)
    {
        v1=printRange_inBST(root->left,low,high);
    }
   else 
    {
       v2=printRange_inBST(root->right,low,high);
    }

    for(int i=0;i<v1.size();i++)
    {
        vec.push_back(v1[i]);
    }
    for(int i=0;i<v2.size();i++)
    {
        vec.push_back(v2[i]);
    }

    return vec;
}
int main()
{
    
    BinarySearchTree<int>* root=takeInputLevelWise();
    // cout<<"give data to search"<<endl;
    // int val;
    // cin>>val;
    // cout<<BST_search(root,val)<<endl;;
    int low,high;
    cout<<"give low and high"<<endl;
    cin>>low>>high;
     vector<int> vec=printRange_inBST(root,low,high);
     sort(vec.begin(),vec.end());
     for(int i=0;i<vec.size();i++)
     {
      cout<<vec[i]<<" ";
     }
    delete root;// to delete the node recursively
   main();
   
}
