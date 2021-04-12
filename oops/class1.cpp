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
    
    
  }
  void setage(int value)
  {
    age=value;
    //we use this method so to set age value as age is private so we need method inside a class to set age value
  }
};


int main()
{
    Student s1; 
    int value;
    cout<<"give age";
    cin>>value;
     s1.setage(value);//to get age  value, we need to call a method as age is private ,we can't assign its value from main
     s1.rollNUmber=101;//since rollno is public so we can directly assign its value
     s1.display();

    Student *s2=new Student; 
    cout<<"give age";
    cin>>value;
    (*s2).setage(value);
    (*s2).rollNUmber=102;
    (*s2).display();

    // OR
    cout<<"give age";
    cin>>value;
    s2->setage(value);
    s2->rollNUmber=103;
    s2->display();

}