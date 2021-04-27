#include<bits/stdc++.h>
using namespace std;

class StackUsingArray{
    int *data;
    int nextIndex;
    int capacity;
    public:
    StackUsingArray(int totalSize){
        data=new int[totalSize];
        nextIndex=0;
        capacity=totalSize;
    }

    // return the number of element present in my stack

    int size(){
        return nextIndex;
    }

    bool isEmpty()
    {
        // if(nextIndex==0 ){
        //     return true;
        // }
        // else{
        //     return false;
        // }

        return nextIndex==0;
    }
    //insert element

    void push(int element){
        if(nextIndex==capacity)
        {
            cout<<"Stack is full"<<endl;
            return;
        }
        data[nextIndex]=element;
        nextIndex++;
    }

    // delete the element
    int pop(){
        if(nextIndex==0)
        {
            cout<<"Stack is Empty"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }
  //to return top most element

  int top(){
      if(nextIndex==0)
      {
          cout<<"Stack is Empty"<<endl;
          return INT_MIN;
      }
      return data[nextIndex-1];
  }
};

int main()
{
    StackUsingArray s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;

}