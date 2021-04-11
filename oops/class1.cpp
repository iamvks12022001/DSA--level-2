#include<bits/stdc++.h>
using namespace std;

class Student{
 public:
  int rollNUmber;
  int age;
};

//how to create the Object and define its property value
int main()
{
    Student s1; //object of student create statically
    // assigning value to statically created obj
     s1.age=24;
     s1.rollNUmber=101;

     cout<<s1.age<<" "<<s1.rollNUmber<<endl;

    Student *s2=new Student; //object of student create dynamically
    //assigning value to dynamically created object
    (*s2).age=25;
    (*s2).rollNUmber=102;
    // OR
     s2->age=26;
     s2->rollNUmber=103;

    cout<<(*s2).age<<" "<<s2->rollNUmber<<endl;

}