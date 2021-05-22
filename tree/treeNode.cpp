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

int main()
{

TreeNode<int>* root = takeInputLevelWise() ;
  printTree(root);

  printLevelWise(root);
  cout<<numberOfNodes(root)<<endl;
  cout<<sumOfNodes(root)<<endl;
  cout<<maxOfNodes(root)<<endl;

  //to Do is to delete the delete
}
