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
//   TreeNode<int>* root=new TreeNode<int>(1);
//   TreeNode<int>* node1=new TreeNode<int>(2);
//   TreeNode<int>* node2=new TreeNode<int>(3);
  
//   root->children.push_back(node1);
//   root->children.push_back(node2);


TreeNode<int>* root =takeInput();
  printTree(root);
  //to Do is to delete the delete
}
