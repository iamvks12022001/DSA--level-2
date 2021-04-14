#include<bits/stdc++.h>
using namespace std;

class Student{
    public:
    int roolNo;
    int age;

    static int totalstudent; //total number of student present

};
int Student ::totalstudent=0; //initialize static data members

int main(){
    Student s1;

    cout<<s1.roolNo<< " "<<s1.age<<endl;
    //cout<<s1.totalstudent ;// not give error but it's logically wrong

    cout<<Student :: totalstudent<<endl;
    s1.totalstudent=20;//this is idle wrong we know that but it work
    Student s2;
    cout<<s2.totalstudent<<endl; //give ans 20
    cout<<Student:: totalstudent<<endl;//give 20 as a ans

}