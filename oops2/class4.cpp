#include<bits/stdc++.h>
using namespace std;

class Student {
    int age;
    char *name;
    public:
    Student(int age,char *name)
    {
        this->age=age;
        //shallow copy (which needed to be avoided)
        //this->name=name;

        //Deep copy (whixh is preferable)
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);

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

    name[3]='e';
    Student s2(24,name);
    s2.display();

    s1.display();//in shalow copy it give answer abce 20
                 //in   deep copy it give answer abcd 20
}
