#include<bits/stdc++.h>
using namespace std;

//making a fracton class which have numerator and denominator and can add to fraction

class fraction{
    private:
    int numerator;
    int denominator;

    public:

    fraction(int numerator ,int denominator)
    {
        this->numerator=numerator;
        this->denominator=denominator;
    }
    void print()
    {
    	cout<<this->numerator<<" "<<denominator<<endl;
    }
    void add(fraction const &f2)   //fraction const & f2=main.f2
    {  //if we want to stop copying then we can use refference variable here i.e add(function &f2)
        //but by this here f2 can change the real (original) value of f2 so it's risky so we use const keyword
        //so that in this block f2 can reffere the main f2 but can not change it's value from this block
        
    	numerator=numerator*(f2.denominator) +  (f2.numerator*denominator);
    	denominator=denominator*(f2.denominator);
    

      simplify(); // or  this->simplify();

    }
    void simplify(){
    	int gcd=1;
    	for(int i=1;i<=min(numerator,denominator);i++)
    	{
    		if(numerator%i==0 && this->denominator%i==0)
    		{
    			gcd=i;
    		}
    	}
    	numerator=numerator/gcd;
    	this->denominator=this->denominator/gcd;

    }
    void multiply(fraction const & f2)
    {
        this->numerator=numerator*f2.numerator;
        denominator=denominator*f2.denominator;

        simplify();

    }
};

int main()
{
   fraction f1(10,2);
   fraction f2(15,4);

   f1.add(f2);
   f1.print();
   f2.print();

   f1.multiply(f2);
   f1.print();
   f2.print();
}