#include<bits/stdc++.h>
using namespace std;
//intializing the roolno so that no one can modify it in future.
class Student {
public:
int age;
const int rollno;


Student(int r ):rollno(r)//=> const int rollno =r; so now rollno not get garbag value
{
}

};

int main()
{
    Student s1(233);
    s1.age=10;
    //s1.rollno=233;
}