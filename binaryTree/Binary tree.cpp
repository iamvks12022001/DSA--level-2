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
void inorder(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

void preorder(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left); 
    preorder(root->right);

}

void postorder(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left); 
    postorder(root->right);
    cout<<root->data<<" ";
    

}
BinaryTreeNode<int>* buildTreefrom_In_PreOrder(vector<int> in,vector<int> pre, int n)
    {
        // Code here
        if(n==0)
        {
            return NULL;
        }
        BinaryTreeNode<int>*root=new BinaryTreeNode<int>(pre.front());
        //search in inorder to get length from left of root;
        int length=0;
        vector<int> in_updated_left;
        vector<int>pre_updated_left;
        for(int i=0;i<n;i++)
        {
            if(in[i]==pre.front())
            {
                break;
            }
            length++;
            in_updated_left.push_back(in[i]);          
            in.erase( in.begin());
        }
         in.erase( in.begin());
         pre.erase( pre.begin());
         for(int i=1;i<=length;i++)
         {
            pre_updated_left.push_back(pre[i]);
            
            pre.erase( pre.begin());
         }
        root->left=buildTreefrom_In_PreOrder(in_updated_left,pre_updated_left,length);
        root->right=buildTreefrom_In_PreOrder(in,pre,n-length-1);

        return root;
    }

BinaryTreeNode<int>* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE) {
	if (inS > inE) {
		return NULL;
	}

	int rootData = pre[preS];
	int rootIndex = -1;
	for (int i = inS; i <= inE; i++) {
		if (in[i] == rootData) {
			rootIndex = i;
			break;
		}
	}

	int lInS = inS;
	int lInE = rootIndex - 1;
	int lPreS = preS + 1;
	int lPreE = lInE - lInS + lPreS;
	int rPreS = lPreE + 1;
	int rPreE = preE;
	int rInS = rootIndex + 1;
	int rInE = inE;
	BinaryTreeNode<int>*  root = new BinaryTreeNode<int>(rootData);
	root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
	root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
	return root;
}

BinaryTreeNode<int>* buildTree(int* in, int* pre, int size) {
	return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1);
}

BinaryTreeNode<int>* buildTreeHelper(vector<int>& postOrder, int postStart, int postEnd, vector<int>& inOrder,
		int inStart, int inEnd) {
	if (postStart > postEnd || inStart > inEnd) {
		return NULL;
	}

	int rootVal = postOrder[postEnd];
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootVal);

	// Find parent element index from inOrder array.
	int k = 0;
	for (int i = inStart; i <= inEnd; i++) {
		if (rootVal == inOrder[i]) {
			k = i;
			break;
		}
	}

	root -> left = buildTreeHelper(postOrder, postStart, postStart + k - inStart - 1, inOrder, inStart, k - 1);
	root -> right = buildTreeHelper(postOrder, postStart + k - inStart, postEnd - 1, inOrder, k + 1, inEnd);

	return root;
}

BinaryTreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) {
	int n = postOrder.size();

	int postStart = 0;
	int postEnd = n - 1;
	int inStart = 0;
	int inEnd = n - 1;

	return buildTreeHelper(postOrder, postStart, postEnd, inOrder, inStart, inEnd);
}
int height(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
int diameter(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int op1=heightOfTree(root->left)+heightOfTree(root->right);
    int op2=diameter(root->left);
    int op3=diameter(root->right);
    return max(op1,max(op2,op3));
}

pair<int, int> heightDiameter(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		pair<int, int> p;
		p.first = 0;
		p.second = 0;
		return p;
	}
	pair<int, int> leftAns = heightDiameter(root->left);
	pair<int,int> rightAns = heightDiameter(root->right);
	int ld = leftAns.second;
	int lh = leftAns.first;
	int rd = rightAns.second;
	int rh = rightAns.first;

	int height = 1 + max(lh, rh);
	int diameter = max(lh + rh, max(ld, rd));
	pair<int, int> p;
	p.first = height;
	p.second = diameter;
	return p;
}

pair<int, int> findMINMAX(BinaryTreeNode<int> *root,pair<int, int>p)
{
    if(root==NULL)
    {
        return p;
    }
    p.first=root->data;
    p.second=root->data;
     pair<int,int> p1;
     pair<int,int> p2;
     p1=findMINMAX(root->left,p);
     p2=findMINMAX(root->right,p);
     p.first=min(p.first,min(p2.first,p1.first));
     p.second=max(p.second,max(p2.second,p1.second));
    
    return p;
}
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
    
    pair<int,int> p=make_pair(INT_MAX,INT_MIN);
    return findMINMAX(root,p);
    
}

 int sumBT(BinaryTreeNode<int>* root)
{
    // Code here
     long int sum=root->data;
    
    if(root->left!=NULL)
    {
       sum+=sumBT(root->left);
    }
       
    if(root->right!=NULL){
        sum+=sumBT(root->right);
    }
    return sum;
    
}
pair<int,bool> isbalanced(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        pair<int,bool> p;
        p.first=0;
        p.second=true;
        return p;
    }

    pair<int,bool> left=isbalanced(root->left);
    pair<int,bool> right=isbalanced(root->right);
    pair<int,bool> p;
    p.first=1+max(left.first,right.first);
    p.second= true;
    if(!(left.second) || !(right.second))
    {
        p.second= false;
    }
    if(abs(left.first-right.first)>1)
    {
       p.second= false;
    }
  

   return p;
}

bool isBalanced_helper(BinaryTreeNode<int>* root)
{
    return isbalanced(root).second;
}

void levelWisetraversal(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
   
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
       BinaryTreeNode<int>* node=q.front();
       q.pop();
       if(node==NULL)
       {
           cout<<endl;
           if(!q.empty()){
           q.push(NULL);
           }
       }else{

        cout<<node->data<<" ";
        
        if(node->left!=NULL)
        {
            q.push(node->left);
        }
        if(node->right!=NULL)
        {
            q.push(node->right);
        }
     }
    }
}
BinaryTreeNode<int>* removeleaf(BinaryTreeNode<int>* root)
{

    if(root->left==NULL && root->right==NULL)
    {
        delete root;
        return NULL;
    }
    
    if(root->left!=NULL){
    root->left=removeleaf(root->left);
    }
    
    if(root->right!=NULL){
    root->right=removeleaf(root->right);
    }

    return root;
}

vector<int> zigzagTreeTraversal(BinaryTreeNode<int> *root)
{
    //    Write your code here.
   
      vector<int> v;
      vector<int> v1;
        if(root==NULL)
        {
            return v;
        }
        queue<BinaryTreeNode<int>* > q;
        q.push(root);
        q.push(NULL);
      
        int count=1;
        while(!q.empty())
        {
            BinaryTreeNode<int> * r1=q.front();
            q.pop();
            if(r1==NULL)
            {
               
                v1.insert(v1.end(),v.begin(),v.end());
                v.clear();
                count++;
                if(!q.empty())
                {
                    q.push(NULL);
                }
            }
            else{
                    
                    if(count%2==0)
                    { v.insert(v.begin(),r1->data);
                     
                     }else{
                           v.push_back(r1->data);
                    }
                      
                    if(r1->left!=NULL)
                    {
                        q.push(r1->left);
                    }
                    if(r1->right!=NULL)
                    {
                        q.push(r1->right);
                    }
                
                }
        }

        return v1;
}
vector<int> siblingNodes(BinaryTreeNode<int> *root)
{
    vector<int> v;
    if(root==NULL)
    {
        return v;
    }
    if(root->left==NULL && root->right!=NULL)
    {
       v.push_back(root->right->data);
    }
    if(root->right==NULL && root->left!=NULL)
    {
      v.push_back(root->left->data);
    }

    if(root->left!=NULL)
    {
        vector<int> v1=siblingNodes(root->left);
        v.insert(v.end(),v1.begin(),v1.end());
    }
    if(root->right!=NULL)
    {
        vector<int> v1=siblingNodes(root->right);
        v.insert(v.end(),v1.begin(),v1.end());
    }
    sort(v.begin(), v.end());
    return v;
}

void CreateDublicate_InsertLeft(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return ;
    }

    BinaryTreeNode<int>* newnode=new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int>*prevnode=root->left;
    root->left=newnode;
    newnode->left=prevnode;
    CreateDublicate_InsertLeft(prevnode);
    CreateDublicate_InsertLeft(root->right);
}
void AllNodein_Array(BinaryTreeNode<int>*root,vector<int>*v)
{
   if(root==NULL)
   {
       return;
   }
   v->push_back(root->data);
   AllNodein_Array(root->left,v);
   AllNodein_Array(root->right,v);

}
void pair_sum(BinaryTreeNode<int> * root,int s)
{
    vector<int> vec;
    AllNodein_Array(root,&vec);
    // for(int i=0;i<vec.size();i++)
    // {
    //     cout<<vec[i]<<" ";
    // }
    sort(vec.begin(), vec.end());
    int i=0;
    int j=vec.size()-1;

    while(i<j)
    {
        if(vec[i]+vec[j]>s)
        {
             j--;
        }else{
            if(vec[i]+vec[j]==s)
            {
                cout<<vec[i]<<" "<<vec[j]<<endl;
                i++;
                j--;
            }else{
                   
                   i++;
            }
        }
    }

}


int lowestCommonAncestor(BinaryTreeNode<int> *root, int x, int y)
{
	//    Write your code here
    int ans=-1;
    if(x==root->data || y==root->data)
    {
        ans=root->data;
        return ans;
    }
    
    int left=-1;
    int right=-1;
    if(root->left!=NULL)
    {
        left=lowestCommonAncestor(root->left,x,y);
    }
    if(root->right!=NULL)
    {
        right=lowestCommonAncestor(root->right,x,y);
    }
    
    if(left==-1 && right==-1)
    {
        return -1;
    }
    if(left!=-1 && right!=-1)
    {
        return root->data;
    }
    
    return (left==-1)?right:left;
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
//    printLevelWise(root);
//    cout<<noOfNode(root)<<endl;
   int Data;
  // cin>>Data;
  // cout<<findAnode(root,Data)<<endl;
//    cout<<heightOfTree(root)<<endl;
 //  mirrorTree(root);
//    printLevelWise(root);
//    inorder(root);
//    cout<<endl;
//    postorder(root);
//    cout<<endl;
//    preorder(root);
//    cout<<endl;


// vector<int>in;
   // vector<int>pre;
   // int n;
   // cout<<"give length of traversal"<<endl;
   // cin>>n;
   // cout<<"give inorder traversal"<<endl;
   // for(int i=0;i<n;i++)
   // {
   //     int data;
   //     cin>>data;
   //     in.push_back(data);
   // }

   // cout<<"give Preorder traversal"<<endl;
   // for(int i=0;i<n;i++)
   // {
   //     int data;
   //     cin>>data;
   //     pre.push_back(data);
   // }
 //   BinaryTreeNode<int>* root1=buildTreefrom_In_PreOrder(in,pre,n);
 //   printLevelWise(root1);

 //   int in[] = {4,2,5,1,8,6,9,3,7};
	// int pre[] = {1,2,4,5,3,6,8,9,7};
	// BinaryTreeNode<int>* root1 = buildTree(in, pre, 9);
 //    vector<int> in1 = {8,4,5,2,6,7,3,1};
	//  vector<int> post = {4,8,2,5,1,6,3,7};
	// BinaryTreeNode<int>* root3 = getTreeFromPostorderAndInorder(in1, post);
	// printTree(root3);

 //    cout<<diameter(root);//O(n*height of tree) appraoch

 //   pair<int, int> p = heightDiameter(root);
	// cout << "Height: " << p.first << endl;
	// cout << "Diameter: " << p.second << endl;

    //O(n approach)


//    cout<<"MIN :"<< getMinAndMax(root).first<<"MAX :"<<getMinAndMax(root).second<<endl;

//    cout<<"SUM is "<<sumBT(root)<<endl;
   
 //  cout<<isBalanced_helper(root)<<endl;

 //  levelWisetraversal(root);
 // cout<<endl;
 //  root=removeleaf(root);
 //  levelWisetraversal(root);
  // cout<<endl;
  // vector<int> v=zigzagTreeTraversal(root);
  // for(int i=0;i<v.size();i++)
  // {
  //     cout<<v[i]<<" ";
  // }
  // cout<<endl;

  // vector<int> v1=siblingNodes(root);
  // for(int i=0;i<v1.size();i++)
  // {
  //     cout<<v1[i]<<" ";
  // }
// levelWisetraversal(root);
// cout<<"----"<<endl;
//   CreateDublicate_InsertLeft(root);

//   levelWisetraversal(root);
// int sum;
// cin>>sum;
//   pair_sum(root,sum);
int x,y;
cin>>x>>y;
cout<<"give x and y"<<endl;
cout<<lowestCommonAncestor(root,x,y)<<endl;
delete root;// to delete the node recursively

    main();
}


//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1