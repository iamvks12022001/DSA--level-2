#include<bits/stdc++.h>
using namespace std;
//why we use private variable
class Student{
 public:
  int rollNUmber;
 private:
  int age;
  public:
  void display()
  {
    cout<<age<<" "<<rollNUmber<<endl;
    //age and roll number can be acceseed easily as function is inside the class
    
    
  }
  void getage()
  {
    cout<<"Age is :"<<age<<endl;
    //to read private variable
  }
  void setage(int value,int password)
  {
    // adding constraint before to set age
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
    //we use this method so to set age value as age is private so we need method inside a class to set age value
  }
};


int main()
{
    Student s1; 
    int value,pass;

    cout<<"give password to set age";
    cin>>pass; //give correct password to be authorizes to edit or set age
    cout<<"give age";
    cin>>value;
    
     s1.setage(value,pass);//to get age  value, we need to call a method as age is private ,we can't assign its value from main
     s1.getage();//to read the private variable;
     s1.rollNUmber=101;//since rollno is public so we can directly assign its value
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

}