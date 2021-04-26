/*
Reverse List in K groups
Difficulty: EASY
Avg. time to solve
15 min
Success Rate
85%
Problem Statement
You are given a linked list of N nodes and an integer K. You have to reverse the given linked list in groups of size K i.e if the list contains x nodes numbered from 1 to x, then you need to reverse each of the groups (1,k),(k+1,2*k), and so on. For example, if the list is 1 2 3 4 5 6 and K = 2, then the new list will be 2 1 4 3 6 5.
As a follow-up, try to solve the question using constant extra space.
Note:
1. In case the number of elements in the last cannot be evenly divided into groups of size k, then just reverse the last group(with any size). For example if the list is 1 2 3 4 5 and K = 3, then the answer would be 3 2 1 5 4.
2. All the node values will be distinct.
Input Format:
The first line of input contains an integer T representing the number of Test cases.
The first line of each test case contains a Linked list whose elements are separated by space and the linked list is terminated by -1.
The second line of each test case contains an integer K.
Output Format:
The one and only line of each test case contains the modified linked list.
Note:
You don’t need to print anything. It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 100   
1 <= N <= 10^4
1 <= K <= 10^4
Time Limit: 1sec
Sample Input 1:
2
1 2 3 4 5 6 -1
2
5 4 3 7 9 2 -1
4 
Sample Output 1:
2 1 4 3 6 5
7 3 4 5 2 9
Explanation Of The Sample Input1:
For the first test case, we reverse the nodes in groups of two, so we get the modified linked list as 2 1 4 3 6 5.
For the second test case, we reverse the nodes in groups of four. But for the last 2 elements, we cannot form a group of four, so we reverse those two elements only. Hence the linked list becomes 7 3 4 5 2 9.
Previous
Next
*/

/****************************************************************
    Following is the Linked List node structure

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

pair<Node*,Node*> solve(Node* head,Node* tail)
{
   if(head==tail)
   {
          pair<Node*,Node*> m1;
          m1.first=tail;
          m1.second=head;
       return m1;
   }
    
    pair<Node*,Node*> m;
    m=solve(head->next,tail); 
     m.second->next=head;
    pair<Node*,Node*> m2;
          m2.first=tail;
          m2.second=head;
    return m2;
    
}
Node* kReverse(Node* head, int K) {
    // Write your code here.
   
    Node* temp=head;
    for(int i=1;i<K && temp->next!=NULL ;i++)
    {
        temp=temp->next;
    }
    Node *ans=NULL;  
    if(temp->next!=NULL){
       
    ans=kReverse(temp->next,K);
    }
    Node *f=NULL;
    Node *e=NULL;
    pair<Node*,Node*>val;
    val=solve(head,temp);
    f=val.first;
    e=val.second;
    e->next=ans;
    return f;

}