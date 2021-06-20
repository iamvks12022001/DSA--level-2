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

class BST {
  BinarySearchTree<int>* root;

  public:

  BST() {
    root = NULL;
  }

  ~BST() {
    delete root;
  }

  private:
  BinarySearchTree<int>* deleteData(int data, BinarySearchTree<int>* node) {
    if (node == NULL) {
      return NULL;
    }

    if (data > node->data) {
      node->right = deleteData(data, node->right);
      return node;
    } else if (data < node->data) {
      node->left = deleteData(data, node->left);
      return node;
    } else {
      if (node->left == NULL && node->right == NULL) {
        delete node;
        return NULL;
      } else if (node->left == NULL) {
        BinarySearchTree<int>* temp = node->right;
        node->right = NULL;
        delete node;
        return temp;
      } else if (node->right == NULL) {
        BinarySearchTree<int>* temp = node->left;
        node->left = NULL;
        delete node;
        return temp; 
      } else {
        BinarySearchTree<int>* minNode = node->right;
        while (minNode->left != NULL) {
          minNode = minNode->left;
        }
        int rightMin = minNode->data;
        node->data = rightMin;
        node->right = deleteData(rightMin, node->right);
        return node;
      }
    }
  }

  void printTree(BinarySearchTree<int>* root) {
    if (root == NULL) {
      return;
    }
    cout << root->data << ":";
    if (root->left != NULL) {
      cout << "L" << root->left->data;
    }

    if (root->right != NULL) {
      cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
  }


  public:
  void deleteData(int data) {
    root = deleteData(data, root);  
  }

  void printTree() {
    printTree(root);
  }

  private:
  BinarySearchTree<int>* insert(int data, BinarySearchTree<int>* node) {
    if (node == NULL) {
      BinarySearchTree<int>* newNode = new BinarySearchTree<int>(data);
      return newNode;
    }

    if (data < node->data) {
      node->left = insert(data, node->left);
    } else {
      node->right = insert(data, node->right);
    }
    return node;
  }

  public:
  void insert(int data) {
    this->root = insert(data, this->root);
  }

  private:
  bool hasData(int data, BinarySearchTree<int>* node) {
    if (node == NULL) {
      return false;
    }

    if (node->data == data) {
      return true;
    } else if (data < node->data) {
      return hasData(data, node->left);
    } else {
      return hasData(data, node->right);
    }
  }

  public:
  bool hasData(int data) {
    return hasData(data, root);
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
 BinarySearchTree<int>* makeBST(vector<int> &arr, int start,int stop)
{
    if(start>stop )
    {
        return NULL;
    }

    int mid=(start+stop)/2;
    BinarySearchTree<int>* newnode=new BinarySearchTree<int>(arr[mid]);
    newnode->left=makeBST(arr,start,mid-1);
    newnode->right=makeBST(arr,mid+1,stop);
     return newnode;
}
BinarySearchTree<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    int mid=n/2;
   BinarySearchTree<int>* root=new BinarySearchTree<int>(arr[mid]);
   root->left=makeBST(arr,0,mid-1);
   root->right=makeBST(arr,mid+1,n-1);
   return root;
}

BinarySearchTree<int>* bstToSortedDLL(BinarySearchTree<int> *root)
{
	// Write your code here.
    if(root==NULL)
    {
        return NULL;
    }
    BinarySearchTree<int>* prev_node=bstToSortedDLL(root->left);
    BinarySearchTree<int>* head=prev_node;
    if(prev_node!=NULL ){
        while(prev_node->right!=NULL)
        {
            prev_node=prev_node->right;
        }
    }
    BinarySearchTree<int>* newnode=new BinarySearchTree<int>(root->data);
    if(prev_node!=NULL){
       prev_node->right=newnode;
    }
    newnode->left=prev_node;
   
    BinarySearchTree<int>* next_node=bstToSortedDLL(root->right);
    if(next_node!=NULL){
      next_node->left=newnode;
    }
    newnode->right=next_node;
 
    return (head==NULL)?newnode:head;
}
struct abc{
    BinarySearchTree<int>* first;
    BinarySearchTree<int>* second;
};
abc bstToSortedDLLHelper(BinarySearchTree<int> *root){
     if(root==NULL)
    {
         abc p1;
         p1.first=NULL;
         p1.second=NULL;
         return p1;
    }
   abc  prev_node=bstToSortedDLLHelper(root->left);
    BinarySearchTree<int>* head=prev_node.first;
   
    BinarySearchTree<int>* newnode=new BinarySearchTree<int>(root->data);
    if(prev_node.second!=NULL){
       prev_node.second->right=newnode;
    }
    newnode->left=prev_node.second;
   
    abc next_node=bstToSortedDLLHelper(root->right);
    BinarySearchTree<int>* tail=next_node.second;
    if(next_node.first!=NULL){
      next_node.first->left=newnode;
    }
    newnode->right=next_node.first;
    abc p2;
    p2.first=(head==NULL)?newnode:head;
    p2.second=(tail==NULL)?newnode:tail;
    return p2;
}
BinarySearchTree<int>* bstToSortedDLL_better(BinarySearchTree<int> *root)
{
	// Write your code here.
    abc p=bstToSortedDLLHelper(root);
    return p.first;
   
}

vector<int>* getRootToNodePath(BinarySearchTree<int>*root,int data)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==data)
    {
        vector<int>* output=new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int>* leftOutput=getRootToNodePath(root->left,data);
    if(leftOutput!=NULL)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int>* rightOutput=getRootToNodePath(root->right,data);
    if(rightOutput!=NULL){
        rightOutput->push_back(root->data);
        return rightOutput;
    }else{
        return NULL;
    }
}
int main()
{
    
  //  BinarySearchTree<int>* root=takeInputLevelWise();
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
    // cout<<isBST(root)<<endl;
    // BinarySearchTree<int>* head= bstToSortedDLL(root);
    // while(root!=NULL)
    // {
    //     cout<<head->data<<" ";
    //     head=head->right;
    // }
    //  BinarySearchTree<int>* head1= bstToSortedDLL_better(root);
    // while(head1!=NULL)
    // {
    //     cout<<head1->data<<" ";
    //     head1=head1->right;
    // }

    // vector<int>* output=getRootToNodePath(root,8);
    // for(int i=0;i<output->size();i++)
    // {
    //     cout<<output->at(i)<<endl;
    // }
    // delete output;

    BST b;
	b.insert(10);
	b.insert(5);
	b.insert(20);
	b.insert(7);
	b.insert(3);
	b.insert(15);
	b.printTree();
	b.deleteData(10);
	b.deleteData(100);
	b.printTree();
    
  //  delete root;// to delete the node recursively
   
   
}
