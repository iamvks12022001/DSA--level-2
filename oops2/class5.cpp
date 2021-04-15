#include<bits/stdc++.h>
using namespace std;
//intializing the roolno so that no one can modify it in future.
class Student {
public:
int age;
const int rollno;
int &x; //age refernce data member


Student(int r,int age ):rollno(r),age(age),x(age)//=> const int rollno =r; so now rollno not get garbag value
{                                                       //int this->age=age;
}                                                        //int &x=age;

};

int main()
{
    Student s1(233,20);
    
}

