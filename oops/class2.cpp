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
    void add(fraction f2)//fraction f2=main.f2 =>fraction f2(main.f2)=> copy constructor is called here.
    {  
    	numerator=numerator*(f2.denominator) +  (f2.numerator*denominator);
    	denominator=denominator*(f2.denominator);
    	//or
    	// this->denominator=this->denominator*(f2.denominator);
    	//note when we call a function by its oject for ex f1.add() then 
    	//f1 address go inside the this keyword

      simpify(); // or  this->simplify();

    }
    void simpify(){
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
}

int main()
{
   
}