/*

Problem Statement
You have given a singly linked list and two integers 'N' and 'M'. Delete 'N' nodes after every 'M' nodes, or we can say more clearly that traverse the linked list such that you retain M nodes then delete next N nodes, continue the same till the end of the linked list.
Input Format :
The first line of input contains the elements of the singly linked list separated by a single space and terminated by -1. Hence, -1 would never be a list element.

The second line contains the two single space-separated integers 'N' and 'M'.
Output Format :
The only line of output contains the resultant linked list after performing required operation denoted as the elements separated by a single space and terminated by -1.
Note :
You do not need to print anything, it has already been taken care.
Constraints :
0 <= L <= 10^6
-10^9 <= data <= 10^9 and data != -1
0 <= N <= 10^6
1 <= M <= 10^6

Where L is the number of nodes in Linked List and N and M are parameters of Problem.


Time Limit: 1 sec
Note :
Try to solve this problem in O(N) time complexity and O(1) space complexity.
Sample Input 1 :
3 2 0 -4 -1
1 1
Sample Output 1 :
3 0 -1
Explanation To Sample Input 1 :
The first and third Nodes are retained, and rest are deleted.
Sample Input 2 :
3 2 0 -4 7 -9 -8 10 5 -1
1 2
Sample Output 2 :
3 2 -4 7 -8 10 -1
Explanation To Sample Input 2 :
The first, second, fourth, fifth, seventh and eighth Nodes are retained, and rest are deleted.
Sample Input 3 :
3 2 0 -4 7 -9 -8 10 5 -1
2 1
Sample Output 3 :
3 -4 -8 -1
Explanation To Sample Input 3 :
The first, fourth and seventh Nodes are retained, and rest are deleted.

*/

//Code

/****************************************************************

    Following is the class structure of the Node class:

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

Node *getListAfterDeleteOperation(Node *head, int n, int m)
{
	//	Write your code here
    Node *ans=head;
    int x=0;
    int y=0;
    Node *prev=NULL;
    while(head!=NULL)
    {
        if(x<m)
        {
            prev=head;
            head=head->next;
            x++;
            y=0;

        }else{
            x=0;
            while(y<n && head!=NULL)
            {
                Node *temp=head;     
                head=head->next;
                if(prev!=NULL){
                prev->next=head;
                }else{
                    ans=NULL;
                }
                delete temp;
                y++;
            }
        }
    }
    return ans;
}