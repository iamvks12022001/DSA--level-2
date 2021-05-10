#include<bits/stdc++.h>
using namespace std;
template<typename T> 

class Node{
    public:
    T data;
    Node<T> *next;
    Node(T data){
        this->data=data;
        next=NULL;
    }
};

template<typename T> 

class QueueUsingLL{
  Node<T> *head;
  Node<T>*tail;
  int size;
  public:
  QueueUsingLL(){
      head=NULL;
      tail=NULL;
      size=0;
  }
  int getSize(){
  return size;
  }

  bool isEmpty(){
   return size==0;
  }
  void enqueue(T element){
   
   Node<T> * newnode=new Node<T>(element);
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;       
    }
  else{
    tail->next=newnode;
    tail=newnode;

     }
    size++;
  }
  T front(){
    if(isEmpty())    //we can use head==NULL here 
    {
        cout<<"Queue is Empty";
        return 0;
    }
    return head->data;
  }
  T dequeue(){
   if(isEmpty())    //we can use head==NULL here 
    {
        cout<<"Queue is Empty";
        return 0;
    }
    Node<T> *temp=head;
    T ans=head->data;
    head=head->next;
    delete temp;
    size--;
    return ans;
  }
};


int main(){
    QueueUsingLL<char> q;
    q.enqueue('a');
    q.enqueue('b');
    q.enqueue('c');
    q.enqueue('d');
    q.enqueue('e');
    q.enqueue('f');

    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;
}