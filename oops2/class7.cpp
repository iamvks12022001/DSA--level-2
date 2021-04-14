#include<bits/stdc++.h>
using namespace std;
//automatic increse of static variable as we create obj of student
class Student{
    public:
    int roolNo;
    int age;

    static int totalstudent; //total number of student present
     Student()
     {
         totalstudent++;
     }
};
int Student ::totalstudent=0; 

int main(){
    Student s1,s2,s3,s4,s5;

 cout<<Student :: totalstudent<<endl;  

}