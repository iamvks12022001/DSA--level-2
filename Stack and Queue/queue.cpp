#include<bits/stdc++.h>
using namespace std;
template<typename T> 
class QueueUsingArray{
    T *data;
    int nextindex;
    int firstindex;
    int size;
    int capacity;
    
    public:
    QueueUsingArray(int s){
        data=new T[s];
        capacity=s;
        nextindex=0;
        firstindex=-1;
        size=0;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    //insert an element

    void enqueue(T element){
        if(size==capacity){
            cout<<"Queue is full"<<endl;
            return;
        }
        data[nextindex]=element; 
        nextindex=(nextindex+1)%capacity;
        if(firstindex==-1){
            firstindex=0;
        }
        size++;
    }

    //delete the element
    T dequeue(){
        if(isEmpty()){  //we cant use firstindex==-1 check bcz what happen when you enqueue 2 element and dequeue 2 element then in that case queue is empty but firstindex!=-1;
            cout<<"Queue is Empty"<<endl;
            return 0; //return 0 can be fixed if either our element is int ,char or boolan
        }
        T ans=data[firstindex];
        firstindex=(firstindex+1)%capacity;
        size--;
        return ans;
    }

   //front element

   T front(){
       if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return 0;   //return 0 can be fixed if either our element is int ,char or boolan
        }
     return data[firstindex];
   }
};


int main(){
  QueueUsingArray<char> q(5);
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