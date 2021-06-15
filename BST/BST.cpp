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
pair<bool,pair<int,int>> isBST_helper(BinarySearchTree<int>* root)
{
   
     pair<bool,pair<int,int>>p_right;
     pair<bool,pair<int,int>>p_left;
     pair<bool,pair<int,int>>p;
     if(root==NULL)
     {
         p=make_pair(true,make_pair(-10000000,-10000000));
         return p;
     }   
        p_left=isBST_helper(root->left);
        p_right=isBST_helper(root->right);
     
        bool ans;
        if(p_left.second.first==-10000000 && p_right.second.first!=-10000000)
        {
            ans= root->data<=p_right.second.first;
            p=make_pair((p_left.first && p_right.first) && ans,make_pair(min(p_right.second.first,root->data),max(p_right.second.second,root->data)));
        }
        else{
                if(p_left.second.first!=-10000000 && p_right.second.first==-10000000)
                {
                    ans= root->data>=p_left.second.second;
                    p=make_pair((p_left.first && p_right.first) && ans,make_pair(min(p_left.second.first,root->data),max(p_left.second.second,root->data)));
                }
                else {
                        if (p_left.second.first==-10000000 && p_right.second.first==-10000000)
                        {
                            ans=true;
                            p=make_pair((p_left.first && p_right.first) && ans,make_pair(root->data,root->data));

                        }
                        else{
                             ans=(p_left.second.second<=root->data && root->data<=p_right.second.first);
                             p=make_pair((p_left.first && p_right.first) && ans,make_pair(min(p_left.second.first,min(p_right.second.first,root->data)),max(p_left.second.second,max(p_right.second.second,root->data))));
                            }
                    }
           }
        
        return p;
}
bool isBST(BinarySearchTree<int>* root)
{
    return isBST_helper(root).first;
}
int main()
{
    
    BinarySearchTree<int>* root=takeInputLevelWise();
    // cout<<"give data to search"<<endl;
    // int val;
    // cin>>val;
    // cout<<BST_search(root,val)<<endl;;
    // int low,high;
    // cout<<"give low and high"<<endl;
    // cin>>low>>high;
    //  vector<int> vec=printRange_inBST(root,low,high);
    //  sort(vec.begin(),vec.end());
    //  for(int i=0;i<vec.size();i++)
    //  {
    //   cout<<vec[i]<<" ";
    //  }
    //  cout<<endl;
     cout<<isBST(root)<<endl;

    delete root;// to delete the node recursively
   main();
   
}
