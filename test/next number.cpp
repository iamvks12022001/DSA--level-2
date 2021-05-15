/*

A number is represented in the form of a linked list such that each digit corresponds to a node in input linked list. You need to add 1 to it and return the updated list.
For example 1234 is represented as (1-> 2-> 3 -> 4) and adding 1 to it should change it to (1 -> 2 -> 3 -> 5).
Input Format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1)
Output Format :
Updated list elements (separated by space)
Constraints :
1 <= n <= 10^5
Sample Input :
4 2 9 -1
Note : -1 at the end of input is just a terminator representing the end of linked list. This -1 is not part of the linked list. Size of given linked list is 3.
Sample Output :
4 3 0

*/


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

int addone(LinkedListNode<int> *head){
     if(head==NULL)
     {
        return 1;
     }

    int ans=addone(head->next);
    int value=head->data + ans;
    head->data=(value)%10;
    return value/10;
}
LinkedListNode<int>* addOne(LinkedListNode<int> *head) {

    /*
     Don't write main().
     Don't read input, it is passed as function argument.
     Write your code here.
    */
    int value=addone(head);
    if(value==1)
    {
     LinkedListNode<int>* newnode= new LinkedListNode<int>(value);
     newnode->next=head;
     head=newnode;
    }
    return head;
}