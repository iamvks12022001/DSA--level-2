#include<bits/stdc++.h>
using namespace std;

template<typename T,typename V> //declare the temporary variable T

class Pair{
    T x;   //use temporary data type T
    V y;
    public:

    void setX(T x){
        this->x=x;
    }

    T getX(){
        return x;
    }

    void setY(V y){
        this->y=y;
    }

     V getY(){
         return y;
     }

};

int main()
{
  Pair<int,double>p1; //we need to define the data type during the creation of object
               //class pair is of int and double data type data member
  Pair<double,double>p2;//class pair is of double,double data type data member
  
   p1.setX(10);
   p1.setY(30.8456);
   cout<<p1.getX()<<" "<<p1.getY()<<endl;

   p2.setX(30.05);
   p2.setY(40.06);
   cout<<p2.getX()<<" "<<p2.getY()<<endl;
   
   Pair<char,string>p3;
   p3.setX('a');
   p3.setY("Vikash Kumar Singh");
   cout<<p3.getX()<<" "<<p3.getY();
}