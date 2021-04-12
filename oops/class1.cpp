#include<bits/stdc++.h>
using namespace std;
// user of this keyword
//' this ' keyword is used to reffered a current object.
//'this ' keyword have address of current object.
// this is pointer
class Student{
 public:
  int rollNUmber;
 private:
  int age;
  public:
  Student()
  {
    //constructor -1
    age=0;
    rollNUmber=0;
  }
   Student(int r) 
  {
       //constructor -2
    this->age=0;//(this is optional to use this here)
    rollNUmber=r;
  }
   Student(int rollNUmber, int age)
  {
      //this will give error bcz both variable reffered to same local variable 
      //in age=age and in rollNumber=rollNUmber

   /*   age=age;
    rollNUmber=rollNUmber;  */
 // so to reffered the obj variable can we do like this s1.age=age (ans NO at that 
 //place we not know s1 and everytime object changes)
 
      //so we have to use 'this' keyword bcz this->age reffered to object variable
    
    (*this).age=age;
     this->rollNUmber=rollNUmber;
  }
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
    Student s1 ;// constructor called
    int value,pass;

    cout<<"give password to set age";
    cin>>pass; 
    cout<<"give age";
    cin>>value;
    
     s1.setage(value,pass);
     s1.getage();
     s1.rollNUmber=101;
     s1.display();

    Student *s2=new Student; // constructor called 
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

    Student s3; //called non -parametrized constructor-1
    s3.display();
    Student *s4=new Student(108);//called parametrized constructor-2
    (*s4).display();
     Student *s5=new Student(108,20);//called parametrized constructor-3
    s5->display();


}