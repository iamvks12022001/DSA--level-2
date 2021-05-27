#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*>children;
    TreeNode(T data)
    {
        this->data=data;
    }

    ~TreeNode(){
        for(int i=0;i<this->children.size();i++)
        {
            delete this->children[i];  //yaha v destructor call hoga delete hona se phela
        }
    }
};

TreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	queue<TreeNode<int>*> pendingNodes;
	
	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter num of children of " << front->data << endl;
		int numChild;
		cin >> numChild;
		for (int i = 0; i < numChild; i++) {
			int childData;
			cout << "Enter " << i << "th child of " << front->data << endl;
			cin >> childData;
			TreeNode<int>* child = new TreeNode<int>(childData); //note if you create node statically then that memory space
              //will be gone when the function end and we cant able to print that node data in other function
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}


template<typename T>
void printTree(TreeNode<T>* root){
    //function to print tree node 
  if(root==NULL)   //edge case
  {
      return;
  }   
    cout<<root->data<<": ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }

}
int sumOfNodes(TreeNode<int>* root)
{
    int sum=root->data;
     for(int i=0;i<root->children.size();i++)
    {
       sum+=sumOfNodes(root->children[i]);
    }
    return sum;
}
int maxOfNodes(TreeNode<int>* root)
{
    int max=root->data;
    for(int i=0;i<root->children.size();i++)
    {
        int temp;
        temp=maxOfNodes(root->children[i]);
        if(temp>max)
        {
            max=temp;
        }

    }
    return max;
}
int numberOfNodes(TreeNode<int>* root)
{
    if(root->children.size()==0)
    { 
        return 1;    //agar base case hata be da tabhi run karega correcty
    }
    int count=0;
    for(int i=0;i<root->children.size();i++)
    {
       count+=numberOfNodes(root->children[i]);
    }
    return count+1;
}
void printLevelWise(TreeNode<int>* root)
{

   queue<TreeNode<int>*> p1;
   p1.push(root);
   while(!p1.empty())
   {
       TreeNode<int>* topnode=p1.front();
       p1.pop();
        cout<<topnode->data<<": ";
        for(int i=0;i<topnode->children.size();i++)
        {
           cout<<topnode->children[i]->data<<",";
           p1.push(topnode->children[i]);
        }
        cout<<endl;
   }
}

int noOfleafNode(TreeNode<int>* root)
{
  int count=0;
   if(root->children.size()==0)
   {
       count++;
       return count;
   }

   for(int i=0;i<root->children.size();i++)
   {
       count+=noOfleafNode(root->children[i]);
   }
   return count;
}

void nodeAtDepth(TreeNode<int>* root,int depth)
{
    if(depth==0)
    {
        cout<<root->data<<" ";
        return;
    }
     for(int i=0;i<root->children.size();i++)
        {
           nodeAtDepth(root->children[i],depth-1);
        }

  return;
}
int heightOfTree(TreeNode<int> *root){

    int max=0;
    for(int i=0;i<root->children.size();i++)
    {
        int temp;
        temp=heightOfTree(root->children[i]);
        if(temp>max)
        {
            max=temp;
        }
    }
    return max+1;
}
TreeNode<int>* takeInput(){
    //funtion to  add a node in Tree

    int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	
	int n;
	cout << "Enter num of children of " << rootData << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}
	return root;

}

void preorder(TreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++)
    {
        preorder(root->children[i]);
    }
}

void postorder(TreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }

    
    for(int i=0;i<root->children.size();i++)
    {
       postorder(root->children[i]);
    }
    cout<<root->data<<" ";
}

void deleteTree(TreeNode<int>* root)
{
   for(int i=0;i<root->children.size();i++)
   {
       deleteTree(root->children[i]);
   }
   
   delete root;
}

bool ContainsX(TreeNode<int>* root,int x){
    if(root->data==x)
    {
        return true;
    }

    for(int i=0;i<root->children.size();i++)
    {
       bool ans= ContainsX(root->children[i],x);
       if(ans==true)
       {
           return true;
       }
    }

    return false;
}

int noofnodegreaterX(TreeNode<int>* root,int x){
    int count=0;
    if(root->data > x)
    {
        count++;
    }

    for(int i=0;i<root->children.size();i++)
    {
       
        count+= noofnodegreaterX(root->children[i],x);
       
    }

    return count;
}
pair<int,int> NodeWithMaxChildSum(TreeNode<int>* root)
{
    int sum=0;
    int max=0;
    sum+=root->data;
    for(int i=0;i<root->children.size();i++)
    {
        sum+=root->children[i]->data;

    }
    int temp=0;
    int temp1=root->data;
    max=sum;
    pair<int,int> nodevalue;
    nodevalue=make_pair(sum,root->data);
    for(int i=0;i<root->children.size();i++)
    {
        
         pair<int,int> nodevalue1=NodeWithMaxChildSum(root->children[i]);
         temp=nodevalue1.first;
         temp1=nodevalue1.second;
        if(max<temp)
        {
            max=temp;
            nodevalue=nodevalue1;
        }
     
    }
    return nodevalue;
}
int nextlarger(TreeNode<int>* root,int value)
{
    
    int min=INT_MAX;
    if(root->data>value)
    {
        min=root->data-value;
    }

    for(int i=0;i<root->children.size();i++)
    {
        int temp=nextlarger(root->children[i],value);
         if(temp<min)
         {
             min=temp;
         }
    }

    return min;
}
bool structurallyIdentical(TreeNode<int> * root,TreeNode<int> * root1)
{
    if (root->data!=root1->data || root->children.size()!=root1->children.size())
    {
        return false;
    }
   
    

    for(int i=0;i<root->children.size();i++)
    {
        bool temp=structurallyIdentical(root->children[i],root1->children[i]);
        if(temp==false)
        {
           return false;
        }
    }

    return true;
}
int main()
{

TreeNode<int>* root = takeInputLevelWise() ;
  printTree(root);

  printLevelWise(root);
  cout<<numberOfNodes(root)<<endl;
  cout<<sumOfNodes(root)<<endl;
  cout<<maxOfNodes(root)<<endl;
  cout<<heightOfTree(root)<<endl;
  nodeAtDepth(root,1);
  cout<<endl;
  cout<<noOfleafNode(root)<<endl;
  preorder(root);
  cout<<endl;
  postorder(root);
  cout<<endl;


  cout<<ContainsX(root,900)<<endl;
  cout<<noofnodegreaterX(root,35)<<endl;
  cout<<NodeWithMaxChildSum(root).second;

// TreeNode<int>* root1 = takeInputLevelWise() ;
// cout<<structurallyIdentical(root,root1)<<endl;

int nl;
cout<<"value of n "<<endl;
cin>>nl;
cout<<nl+nextlarger(root,nl)<<endl;

  //to Do is to delete the delete

 // deleteTree(root);   one way to deletre the tree

 delete root;//delete throw destructor
 //concept is when we delete something then usase phela destructor call hoga
 //so root delete hona se phela destructor call hoga
 //and destructor fir saare children ko delete kar dega.

main();

}
