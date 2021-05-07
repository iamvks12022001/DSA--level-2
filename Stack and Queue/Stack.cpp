#include<bits/stdc++.h>
using namespace std;
template<typename T> 
class StackUsingArray{
    T *data;
    int nextIndex;
    int capacity;
    public:
    StackUsingArray(){
        data=new T[4];
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

    void push(T element){
        if(nextIndex==capacity)
        {
            //create new array
            T *newdata=new T[2*capacity];
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

    T pop(){
        if(nextIndex==0)
        {
            cout<<"Stack is Empty"<<endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

  T top(){
      if(nextIndex==0)
      {
          cout<<"Stack is Empty"<<endl;
          return 0;
      }
      return data[nextIndex-1];
  }
};

int main()
{
    StackUsingArray<char> s; //now char is also passed in our stack
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('e');
    s.push('f');
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;

    StackUsingArray<double> s1; //now char is also passed in our stack
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);
    cout<<s1.top()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.size()<<endl;
    cout<<s1.isEmpty()<<endl;

}