#include<bits/stdc++.h>
using namespace std;
//inbuilt constructor 
//1.default constructor -already discussed
//2.copy constructor -not need to define it's created automaticaly
        //copy construtor make copy of object which is passed
        //ex..  student s2(s1);
        // it means s2.rollNUmber=s1.rollNUmber and s2.age=s1.age;
//3.copy assignment operator -not need to define it's created automaticaly
        //ex..  student s1(10,100),s2(20,200); 
              // s2=s1;
              //it means s2.age=s1.age and s2.rollNUmber=s1.rollNUmber 
//4.destructor -not need to define it's created automaticaly
        //  use to deallocate the memory of object
        //it have same name as of class,no return type,no input argument
        //~ symbol is use before class name to make a destructor
        //called once in a life time of object
        //destructor is called just when object lost its scope or going to be destroy
        //note when function end all the Student object which is created statically 
        //distroyed automatically so student destructor also get called
        //but when obj is created dynamically then we have explicitly delete all the 
        //dynamically created obj so that it's destructor also get called otherwise it's
        //destructor not get called
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