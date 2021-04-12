#include<bits/stdc++.h>
using namespace std;
// user define constructor(parametrized and non parametrized)
// note as soon as we create your own constructor then default constructor get removed 
//intiliazed with defined value

class Student{
 public:
  int rollNUmber;
 private:
  int age;
  public:
  Student()//non parametrized constructor
  {
    //constructor -1
    age=0;
    rollNUmber=0;
  }
   Student(int r) //parametrized constructor
  {
       //constructor -2
    age=0;
    rollNUmber=r;
  }
   Student(int r, int a) //parametrized constructor
  {
       //constructor -3
    age=a;
    rollNUmber=r;
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

// note if you doesnot have non parmetrized constructor but have parametrized constructor
//and you make object without passing argument then compiler give error bcz as you have parmetrized constructor then 
//it means default constructor is gone and there is no any constructor left to called object of no argument.
}