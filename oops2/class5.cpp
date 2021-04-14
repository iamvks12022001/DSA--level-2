#include<bits/stdc++.h>
using namespace std;

class Student {
public:
int age;
const int rollno;

};

int main()
{
    Student s1;// this will call deafult constructor and set a constant
    // variale roll no as a garbage value so it give error
    s1.age=10;
    s1.rollno=233;
}