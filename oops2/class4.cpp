#include<bits/stdc++.h>
using namespace std;

class Student {
   
    int age;
     public:
    char *name;
    public:
    Student(int age,char *name)
    {
        this->age=age;
        
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);

    }
    //redefining copy constructor to solve problem of shallow copy

    Student(Student s)//again Student s=main.s1=> s(s1)=>agin call copy constructor
    {                 //(which is define by us as default constructor is gone) so it go for infinte loop
        this->age=s.age;
        //Deep Copy
        this->name=new char[strlen(s.name)+1];
        strcpy(name,s.name);

    }
    void display()
    {
        cout<<name<<" "<<age<<endl;
    }

};

int main()
{
    char name[]="abcd";
    Student s1(20,name);
    s1.display();

   Student s2(s1);
    name[0]='e';//this will not change name in object s1 and s2
    s1.name[0]='x';//this will change name in both s1 and s2 so act like shallow copy
 
    s2.display();
    s1.display();
}
