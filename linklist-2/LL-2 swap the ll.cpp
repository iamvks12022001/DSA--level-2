/*

You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
Example 3:

Input: head = [1], k = 1
Output: [1]
Example 4:

Input: head = [1,2], k = 1
Output: [2,1]
Example 5:

Input: head = [1,2,3], k = 2
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 105
0 <= Node.val <= 100

*/

// code

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        int n=0;
        int back=k;
        ListNode *s1=NULL;
        ListNode *p1=NULL;
        ListNode *s2=NULL;
        ListNode *p2=NULL;
         ListNode *temp=NULL;
        ListNode *temp41=NULL;
          ListNode *temp1=head;
         ListNode *ans=head;
        while(head!=NULL)
        {
             k--;
           if(k==0)
           {
                //cout<<"pp";
               s1=head;
               p1=temp;
           }
            n++;
            temp=head;
            head=head->next;
           
        }
        
        back=n-back+1;
      //  cout<<back;
        while(temp1!=NULL)
        {
             back--;
           if(back==0)
           {
              // cout<<"hh";
               s2=temp1;
               p2=temp41;
           }
            
            temp41=temp1;
            temp1=temp1->next;
           
        }
  //      cout<<s1->val<<p1->val<<s2->val<<p2->val;
        if(s1!=NULL && s2!=NULL && s1!=s2){
       ListNode* temp3=s2->next;
        if(p1==NULL){
            ans=s2;
        }else{
        p1->next=s2;
        }
        if( s2==s1->next)
        {
            s2->next=s1;
        }else{ 
        s2->next=s1->next;
        }
        if(p2==NULL){
            
            ans=s1;
        }
        else{ 
        p2->next=s1;
        }
        if(s1==temp3){
            s1->next=s2;
        }
            else{
        s1->next=temp3;
            }
        }
        return ans;
    }
};