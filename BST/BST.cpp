/*

Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Note: This question is the same as 538: https://leetcode.com/problems/convert-bst-to-greater-tree/

 

Example 1:


Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
Example 2:

Input: root = [0,null,1]
Output: [1,null,1]
Example 3:

Input: root = [1,0,2]
Output: [3,3,2]
Example 4:

Input: root = [3,2,4,1]
Output: [7,9,4,10]
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
0 <= Node.val <= 100
All the values in the tree are unique.
root is guaranteed to be a valid binary search tree.

*/



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

int lowestCommonAncestorIN_BST(BinarySearchTree<int> *root, int x, int y)
{
	//    Write your code here
    int ans=-1;
    if(root->data>=min(x,y) && root->data<=max(x,y))
    {
      ans=root->data;
      return ans;
    }
    
    
    
    if(root->data> x && root->left!=NULL)
    {
        ans=lowestCommonAncestorIN_BST(root->left,x,y);
    }
    if(root->data< x && root->right!=NULL)
    {
        ans=lowestCommonAncestorIN_BST(root->right,x,y);
    }
    
    if(ans==-1)
    {
        return -1;
    }

    return ans;
}
pair<bool,tuple<int,int,int>> largestBST_helper(BinarySearchTree<int>* root) {
    
     if(root==NULL)
     {
          pair<bool,tuple<int,int,int>>p=make_pair(true,make_tuple(INT_MAX,INT_MIN,0));
          return p;     
     }

     pair<bool,tuple<int,int,int>>p1=largestBST_helper(root->left);
     pair<bool,tuple<int,int,int>>p2=largestBST_helper(root->right);
     
     int height=max(get<2>(p1.second),get<2>(p2.second));
      pair<bool,tuple<int,int,int>>p4;
     if(p1.first==false || p2.first==false)
     {
         p4=make_pair(false,make_tuple(get<1>(p1.second),get<0>(p2.second),height));
         return p4;
     }
     if(get<1>(p1.second)<root->data && get<0>(p2.second)>root->data)
     {
       int x=get<0>(p1.second);
       int y=get<1>(p2.second);
         if(x==INT_MAX)
         {
          x=root->data;
         
         }
         if(y==INT_MIN)
         {
          y=root->data;
         
         }
         height=get<2>(p1.second)+get<2>(p2.second);
         pair<bool,tuple<int,int,int>>p3=make_pair(true,make_tuple(x,y,height+1));
         return p3;
     }
     p4=make_pair(false,make_tuple(get<1>(p1.second),get<0>(p2.second),height));
     return p4;

}
int largestBST(BinarySearchTree<int>* root) {
    
     pair<bool,tuple<int,int,int>>p1=largestBST_helper(root); 
     return get<2>(p1.second);

}

int convertBstToGreaterSum_helper(BinarySearchTree<int> *root,int overhead)
{
    if(root->left==NULL && root->right==NULL)
    {
      root->data=overhead+root->data;
      return root->data;
    }
    int o1=0;
    int o2=0;
    if(root->right!=NULL){
     o1=convertBstToGreaterSum_helper(root->right,overhead+0);
    }
    root->data=root->data+max(o1,overhead);
     if(root->left!=NULL){
    o2=convertBstToGreaterSum_helper(root->left,root->data);
     }

    return max(o2,root->data);
}

BinarySearchTree<int> *convertBstToGreaterSum(BinarySearchTree<int> *root)
{
   
    int val=convertBstToGreaterSum_helper(root,0);
    return root;
}

int countNodes(BinarySearchTree<int> *root) {
    if (root == NULL) {
        return 0;
    }

    return countNodes(root->left) + countNodes(root->right) + 1;
}

void printNodesSumToS(BinarySearchTree<int> *root, int s) {
    if (root == NULL) {
        return;
    }

    int totalCount = countNodes(root);
    int count = 0;

    stack<BinarySearchTree<int> *> inorder;
    stack<BinarySearchTree<int> *> revInorder;

    BinarySearchTree<int> *currentNode = root;
    while (currentNode != NULL) {
        inorder.push(currentNode);
        currentNode = currentNode->left;
    }

    currentNode = root;
    while (currentNode != NULL) {
        revInorder.push(currentNode);
        currentNode = currentNode->right;
    }

    while (count < totalCount - 1) {
        BinarySearchTree<int> *inorderTop = inorder.top();
        BinarySearchTree<int> *revInorderTop = revInorder.top();
        if (inorderTop->data + revInorderTop->data == s) {
            cout << inorderTop->data << " " << revInorderTop->data << endl;

            BinarySearchTree<int> *top = inorderTop;
            inorder.pop();
            count++;
            if (top->right != NULL) {
                top = top->right;
                while (top != NULL) {
                    inorder.push(top);
                    top = top->left;
                }
            }

            top = revInorderTop;
            revInorder.pop();
            count++;
            if (top->left != NULL) {
                top = top->left;
                while (top != NULL) {
                    revInorder.push(top);
                    top = top->right;
                }
            }
        } else if (inorderTop->data + revInorderTop->data > s) {
            BinarySearchTree<int> *top = revInorderTop;
            revInorder.pop();
            count++;
            if (top->left != NULL) {
                top = top->left;
                while (top != NULL) {
                    revInorder.push(top);
                    top = top->right;
                }
            }
        } else {
            BinarySearchTree<int> *top = inorderTop;
            inorder.pop();
            count++;
            if (top->right != NULL) {
                top = top->right;
                while (top != NULL) {
                    inorder.push(top);
                    top = top->left;
                }
            }
        }
    }
}
struct dir{
    BinarySearchTree<int>* first;
    int second;
};
vector<dir> pathToTarget(BinarySearchTree<int>* root, BinarySearchTree<int>* target)
{
    if(root ==NULL)
    {
        vector<dir>v;
        return v;
    }
    if(root==target)
    {
        vector<dir>v2;
        dir d1;
        d1.first=root;
        d1.second=2;
            v2.push_back(d1);
        return v2;
    }
     vector<dir>v1;
        dir d1;
        d1.first=root;
        d1.second=0;//left
     v1=pathToTarget(root->left,target);
    if(v1.size()==0){
       v1=pathToTarget(root->right,target);
        d1.first=root;
        d1.second=1;//right
    }
    if(v1.size()!=0)
    {
        v1.push_back(d1);
    }
    return v1;
}

vector<BinarySearchTree<int>*> printALLnodeuptoDi_K(BinarySearchTree<int>* root,int d,int k)
{
    if(root==NULL)
    {
        vector<BinarySearchTree<int>*> a;
        return a;
    }
    if(k==0)
    {
        vector<BinarySearchTree<int>*> v;
        v.push_back(root);
        return v;
    }
     vector<BinarySearchTree<int>*> ans;
    if(d==0)
    {
        ans=printALLnodeuptoDi_K(root->right,2,k-1);
    }
    if(d==1)
    {
        ans=printALLnodeuptoDi_K(root->left,2,k-1);
    }
    if(d==2)
    {
        vector<BinarySearchTree<int>*> temp;
        ans=printALLnodeuptoDi_K(root->left,2,k-1);
        temp=printALLnodeuptoDi_K(root->right,2,k-1);
        for(int i=0;i<temp.size();i++)
        {
            ans.push_back(temp[i]);
        }
    }
    return ans;
}
vector<BinarySearchTree<int>*> printNodesAtDistanceK(BinarySearchTree<int>* root, BinarySearchTree<int>* target, int k) {
    // Write your code here.
    if(root==NULL)
    {
        vector<BinarySearchTree<int>*> v;
        return v;
    }

  vector<dir> v1=pathToTarget(root,target);
//     for(int i=0;i<v1.size();i++)
//     {
//         cout<<(v1[i].first)->data<<" "<<(v1[i].second)<<endl;
//     }
    vector<BinarySearchTree<int>*> ans;
    for(int i=0;i<v1.size();i++)
    {     
        if(k-i<0)
        {
            break;
        }
         vector<BinarySearchTree<int>*> temp;
         temp= printALLnodeuptoDi_K(v1[i].first,v1[i].second,k-i);
        for(int i=0;i<temp.size();i++)
        {
            ans.push_back(temp[i]);
        }
    }
   return ans;
}
 BinarySearchTree<int>* targetnode( BinarySearchTree<int>* root,int data)
 {
   if(root==NULL)
   {
     return NULL;
   }
   if(root->data==data)
   {
     return root;
   }
  
  BinarySearchTree<int>* temp;
  temp=targetnode(root->left,data);
  if(temp==NULL)
  {
    temp=targetnode(root->right,data);
  }

return temp;
 }
int pathRootToLeaf(BinarySearchTree<int>* root,int k,vector<int> s,int sum,vector<vector<int>>& v1)
{
  if(root->left==NULL && root->right==NULL)
  {
    s.push_back(root->data);
    sum+=root->data;
    
    if(k==sum)
    {
      v1.push_back(s);
      return 1;
    }
    return 0;
  }
  
  s.push_back(root->data);
  sum+=root->data;
  int l=0;
  int r=0;
  if(root->left!=NULL){
   l=pathRootToLeaf(root->left,k,s,sum,v1);
  }
  if(root->right!=NULL){
   r=pathRootToLeaf(root->right,k,s,sum,v1);
  }

  return l+r;

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

  //   BST b;
	// b.insert(10);
	// b.insert(5);
	// b.insert(20);
	// b.insert(7);
	// b.insert(3);
	// b.insert(15);
	// b.printTree();
	// b.deleteData(10);
	// b.deleteData(100);
	// b.printTree();
  // int x,y;
  // cout<<"give x and y"<<endl;
  // cin>>x>>y;
  //   cout<<lowestCommonAncestorIN_BST(root,x,y)<<endl;

  // cout<<largestBST(root)<<endl;
  //  delete root;// to delete the node recursively
  //  int sum;
  //  cin>>sum;
  // printNodesSumToS(root,sum);
  // int k;
  // cin>>k;
  // int targetdata;
  // cin>>targetdata;
  // BinarySearchTree<int>* target=targetnode(root,targetdata);
  //   vector<BinarySearchTree<int>*>v=  printNodesAtDistanceK(root,target, k);
  //   for(int i=0;i<v.size();i++)
  //   {
  //     cout<<v[i]->data<<" ";
  //   }
int k;
cin>>k;
vector<int> v;
vector<vector<int>> v1;
cout<<pathRootToLeaf(root,k,v,0,v1);//this give total number of path avl
//v1 is ans basically this return paths
   main();
   
}
