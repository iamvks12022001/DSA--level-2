
/*

Rearrange and return a linked list in such a way that all odd position nodes are together and all even positions node are together
You just need to return the head of new linked list, don't print the elements.
Input Format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1)
Output Format :
Updated list elements (separated by space)
Constraints :
1 <= n <= 10^5
Sample Input :
1 2 3 4 5 6 7 8 -1
Note :
-1 at the end of input is just a terminator representing the end of linked list. This -1 is not part of the linked list. Size of given linked list is 4.
Sample Output :
1 3 5 7 2 4 6 8
Input: 2 1 3 5 6 4 7
Output: 2 3 6 7 1 5 4

*/


//SOLUTION

/****************************************************************
Following is the Linked list node structure already written

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T>* next;
    LinkedListNode(T data)
    { 
        this->data = data;
        next = NULL;
    }
};
*****************************************************************/

#include<bits/stdc++.h>
using namespace std;

LinkedListNode<int> *rearrangeEvenOdd(LinkedListNode<int> *head) {

    /*
     Don't write main().
     Don't read input, it is passed as function argument.
     Write your code here.
    */
    LinkedListNode<int> *ans=head;
    int first=0;
    LinkedListNode<int> *prev=NULL;
    vector< LinkedListNode<int>* > li;
    int index=1;
    while(head!=NULL)
    {
       
        if(index%2==0)
        {
           li.push_back(head); 
        }
        else{
            if(first==0)
            {
                ans=head;
                first++;
            }
            if(prev!=NULL){
            prev->next=head;
            }
             prev=head;
        }
        head=head->next;
        index++;
    }
    LinkedListNode<int> *temp=NULL;
    for(int i=0;i<li.size();i++){
        temp=li[i];
        if(prev!=NULL){
        prev->next=temp;
        }
        prev=temp;
        temp->next=NULL;
    }
  return ans;
}