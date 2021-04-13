#include<bits/stdc++.h>
using namespace std;
//creating class for complexNum number adding and multiplying
class complexNum{
    private:
    int real;
    int imaginary;

    public:
    complexNum(int real ,int imaginary)
    {
        this->real=real;
        this->imaginary=imaginary;
    
     }

    void plus(complexNum const &c2)
    {
        real=real+c2.real;
        imaginary=imaginary+c2.imaginary;
        
    }
    void multiply(complexNum const &c2)
    {
        int num1=(real*c2.real)-(imaginary * c2.imaginary);
        int num2=real*c2.imaginary + (imaginary*c2.real);
         real=num1;
         imaginary=num2;
        
    }   
    void print()
    {
        cout<<real<<" i"<<imaginary<<endl;
    } 
};

int main(){
    int  real1,imaginary1,real2,imaginary2;

    cin>>real1>>imaginary1;
    cin>>real2>>imaginary2;
    complexNum c1(real1,imaginary1);
    
    complexNum c2(real2,imaginary2);

    int choice;
    cin>>choice;

    if(choice==1)
    {

     c1.plus(c2);
     c1.print();
     c2.print();
    }else if(choice==2){
      
      c1.multiply(c2);
      c1.print();
      c2.print();
    }
    else{
        return 0;
    }
    

}