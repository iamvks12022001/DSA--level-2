#include<bits/stdc++.h>
using namespace std;
// copy assignment operator id not a constructor
 //copy assignment operator work only when both of its object already in memory
 //ex...Student s1,s2;
       //s1=s2  this is copy assignment operator
// note this statement student s1=s2; is not copy assignment operator as s2 is not in memory
// this line is interpreted as Student s1=s2;=> Student s1(s2); i.e call copy constructor
class Student{
 public:
  int rollNUmber;
 private:
  int age;
  public:
  Student()
  {
    age=0;
    rollNUmber=0;
  }
   Student(int r) 
  {
 
    this->age=0;
    rollNUmber=r;
  }
   Student(int rollNUmber, int age)
  {
    
    (*this).age=age;
     this->rollNUmber=rollNUmber;
  }
  ~Student(){
  	cout<<"DESTRuctor"<<endl;
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
    Student s1 ;
    int value,pass;

    cout<<"give password to set age";
    cin>>pass; 
    cout<<"give age";
    cin>>value;
    
     s1.setage(value,pass);
     s1.getage();
     s1.rollNUmber=101;
     s1.display();

    Student *s2=new Student; 
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

    Student s3; 
    s3.display();
    Student *s4=new Student(108);
    (*s4).display();
     Student *s5=new Student(108,20);
    s5->display();

    Student* s6=new Student((*s5)); //copy constructor called for s6
    s6->display();

    Student s7(s1);//copy constructor called for s7
    s1.display();

    Student* s8=new Student(s1); //copy constructor called for s8
    s8->display();

    Student s9(100,10); //copy assignment operator for statical variable
    s9=s1;
    s9.display();

    s9=(*s2);
    s9.display();

    Student *s10=new Student(100,10);//copy assignment operator for dynamical variable
    (*s10)=s1;
    s10->display();
    (*s10)=(*s2);
    s10->display();
    
    //explicitely deleting so that it's destructor gets called
    delete s2;
    delete s4;
    delete s5;
    delete s6;
    delete s8;
    delete s10;
     


}