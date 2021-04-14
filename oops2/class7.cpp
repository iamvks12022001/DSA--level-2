#include<bits/stdc++.h>
using namespace std;
//static function to calculate total number of student
class Student{
    private:
        static int totalstudent; //total number of student present
    public:
        int roolNo;
        int age;

    
     Student() //constructor increase the count of total student
     {
         totalstudent++;
     }
    static int getTotalStudent(){
         return totalstudent;
     }
};
int Student ::totalstudent=0; 

int main(){
    Student s1,s2,s3,s4,s5;

 cout<<Student :: getTotalStudent()<<endl;  //to access static date member

}