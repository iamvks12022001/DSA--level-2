#include<bits/stdc++.h>
using namespace std;
// constructor
//every constructor -must be called only one time in each object life (during object creation),work is to initilize the object property value,
//not have return type, function name same as class name,for evey object a constructor is called either by deafult constructor or
// user defined constructor
//type of constructor-default,non perametrized,perametrized constructor

// default constructor -no input(argument),not need to define the
//constructor in class(it's generated automatically),initilize with garbage value.

//structure of default constructer(present inside a Student class in background)

// student(){

// };

class Student{
 public:
  int rollNUmber;
 private:
  int age;
  public:
  void display()
  {
    cout<<age<<" "<<rollNUmber<<endl;
    
    
    
  }
  void getage()
  {
    cout<<"Age is :"<<age<<endl;
  }
  void setage(int value,int password)
  {
    if(password!=1234)
    {
      cout<<"not authorizes to access as password is wrong "<<endl;
      return;
    }
    if(value <0)
    {
      return ;
    }
    age=value;
  }
};


int main()
{
    Student s1 ;// default constructor is called as just when you create a student object
   //we not need to define the student constructer in class as it is generated automatically as 
   //soon as you create student class
    int value,pass;

    cout<<"give password to set age";
    cin>>pass; 
    cout<<"give age";
    cin>>value;
    
     s1.setage(value,pass);
     s1.getage();
     s1.rollNUmber=101;
     s1.display();

    Student *s2=new Student; // default constructor is called 
    cout<<"give age";
    cin>>value;
    (*s2).setage(value,pass);
    (*s2).getage();
    (*s2).rollNUmber=102;
    (*s2).display();

    // OR
    cout<<"give age";
    cin>>value;
    s2->setage(value,pass);
    s2->getage();
    s2->rollNUmber=103;
    s2->display();

}