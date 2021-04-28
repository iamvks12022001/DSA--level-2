#include<bits/stdc++.h>
using namespace std;

class StackUsingArray{
    int *data;
    int nextIndex;
    int capacity;
    public:
    StackUsingArray(){
        data=new int[4];
        nextIndex=0;
        capacity=4; //fixing the size of arraay at initiale satge
    }


    int size(){
        return nextIndex;
    }

    bool isEmpty()
    {
        

        return nextIndex==0;
    }

    void push(int element){
        if(nextIndex==capacity)
        {
            //create new array
            int *newdata=new int[2*capacity];
            for(int i=0;i<capacity;i++)
            {
                newdata[i]=data[i];
            }
            capacity=2*capacity;
            delete[] data; //The delete operator deallocates memory and calls the 
                          //destructor for a single object created with new.
                          // The delete [] operator deallocates memory and calls
                         // destructors for an array of objects created with new [].
            data=newdata;

        }
        data[nextIndex]=element;
        nextIndex++;
    }

    int pop(){
        if(nextIndex==0)
        {
            cout<<"Stack is Empty"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

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
    StackUsingArray s;
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