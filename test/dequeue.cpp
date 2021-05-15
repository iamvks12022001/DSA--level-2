#include<bits/stdc++.h>
using namespace std;

class Deque
{
    int *arr;
    int capacity;
    int size;
    
public:
    // Initialize your data structure.
    Deque(int n)
    {       
        // Write your code here.
        arr=new int [n];
        capacity=n;
        size=0;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
        if(size==capacity)
        {
            return false;
        }
          for(int i=size-1;i>=0;i--)
        {
            arr[i+1]=arr[i];
        }
        arr[0]=x;
        size++;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
         if(size==capacity)
         {
            return false;
         }

         
        arr[size]=x;
        size++;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if(size==0)
        {
            return -1;
        }
        int value=arr[0];
        for(int i=1;i<size;i++)
        {
            arr[i-1]=arr[i];
        }
        size--;
        return value;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if(size==0)
        {
            return -1;
        }
        int value=arr[size-1];
      
        size--;
        return value;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(size==0)
        {
            return -1;
        }
        int value=arr[0];
 
        return value;
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
         if(size==0)
        {
            return -1;
        }
        int value=arr[size-1];
 
        return value;
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if(size==0)
        {
            return true;
        }
        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
         if(size==capacity)
        {
            return true;
        }

        return false;
     }
};
int main(){
    int N,Q;
    cin>>N>>Q;
    Deque d(N);
    for(int i=0;i<Q;i++){
        int  P;
        cin>>P;
        if(P==1||P==2)
        {
            int X;
            cin>>X;
            (P==1)?  cout<< d.pushFront(X)<<endl:  cout<< d.pushRear(X)<<endl;      
        }else{
            if(P==3)
            {
                cout<<d.popFront()<<endl;
            }
            if(P==4)
            {
                cout<<d.popRear()<<endl;
            }
            if(P==5)
            {
                cout<<d.getFront()<<endl;
            }
            if(P==6)
            {
                cout<<d.getRear()<<endl;
            }
            if(P==7)
            {
                cout<<d.isEmpty()<<endl;
            }
            if(P==8)
            {
                cout<<d.isFull()<<endl;
            }
        }
    }
}
