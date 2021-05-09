#include<bits/stdc++.h>
using namespace std;
template<typename T> 

class node{
    public:
   T data;
   node<T> *next; //bcz node class T se bani ha

   node(T data)
   {
       this->data=data;
       next=NULL;
   }

};
template<typename T>  //for StackLL we have to again specify what is T

class StackLL{
    node<T>* head;
    int size;
    public:
  StackLL()
   {
      head=NULL;
      size=0;
   }

   int getSize(){
       return size;
   }

   bool isEmpty(){
        if(head==NULL)
       {
           return true;
       }
       return false;
   }

  void push(T element){
      node<T>* newnode=new node<T>(element);
      newnode->next=head;
      head=newnode;
      size++;
     
  }
  T pop(){
      if(head==NULL)
      {
          cout<<"Stac is empty"<<endl;
          return 0;
      }
    node<T> *temp=head;
    T ans=head->data;
    head=head->next;
    size--;
    delete temp;
    return ans;

  }
  T top(){
    if(head==NULL)
    {
         cout<<"Stac is empty"<<endl;
          return 0;
    }
    return head->data;
  }
};

int main(){
    StackLL<char>s;
    s.push('a');  
    s.push('b'); 
    s.push('c'); 
    s.push('d'); 
    s.push('e');

    cout<<s.top()<<endl; 
    cout<<s.pop()<<endl; 
    cout<<s.top()<<endl; 

    cout<<s.pop()<<endl; 
    cout<<s.getSize()<<endl; 
    cout<<s.pop()<<endl; 
    cout<<s.pop()<<endl; 
    cout<<s.pop()<<endl; 
    cout<<s.isEmpty()<<endl; 

}