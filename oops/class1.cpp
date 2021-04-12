#include<bits/stdc++.h>
using namespace std;
//how to access private variable
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
    //age value is garbage value as age is private variable and so cannot be set inside the main
    
  }
};


int main()
{
    Student s1; 
    // s1.age=24; can not be accessed as  age is private varible and it is outside the class 
     s1.rollNUmber=101;

    //how to call class method for statical variable
    s1.display();

    Student *s2=new Student; 
    //(*s2).age=25; can not be accessed as  age is private varible and it is outside the class 
    (*s2).rollNUmber=102;
    // calling display method for dynamical variable
    (*s2).display();

    // OR
    // s2->age=26;can not be accessed as  age is private varible and it is outside the class 
     s2->rollNUmber=103;
    // calling display method for dynamical variable
     s2->display();

}