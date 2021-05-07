#include<bits/stdc++.h>
using namespace std;

template<typename T,typename V> 

class Pair{
    T x;  
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
  Pair<int,double>p1; 
  Pair<double,double>p2;
  
   p1.setX(10);
   p1.setY(30.8456);
   cout<<p1.getX()<<" "<<p1.getY()<<endl;

   p2.setX(30.05);
   p2.setY(40.06);
   cout<<p2.getX()<<" "<<p2.getY()<<endl;
   
   Pair<char,string>p3;
   p3.setX('a');
   p3.setY("Vikash Kumar Singh");
   cout<<p3.getX()<<" "<<p3.getY()<<endl;

   Pair<Pair<int ,int>,int> p4;  //if we want to create three  data memeber in same class
   p4.setY(10);                // p4 is object of pair type and int type
   Pair<int,int>p5;
   p5.setX(5);
   p5.setY(16);
   p4.setX(p5);

   cout<<p4.getX().getX()<<" "<<p4.getX().getY()<<" "<<p4.getY()<<endl;

   //if we want to create the pair of 3 data memeber of int double and char type
   //then create p6 in this maanner Pair<Pair<int ,double>,char> and crate p7 of Pair<int,double>
   // and use similary for 4 ,5 ..etc
}