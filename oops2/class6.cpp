#include<bits/stdc++.h>
using namespace std;

//constant function

class fraction{
    private:
    int numerator;
    int denominator;

    public:

    fraction(){

    }

    fraction(int numerator ,int denominator)
    {
        this->numerator=numerator;
        this->denominator=denominator;
    }

    int getNumerator() const {   //to read private variable
        return numerator;
    }
    int  getDenumerator() const  { //to read private variable
        return denominator;
    }
    void setNumerator(int n){ //to set private variable
        numerator=n;
    }
    void setDenominator(int d){ //to set private variable
        denominator=d;
    }
   
    void print() const
    {
    	cout<<this->numerator<<" "<<denominator<<endl;
    }
    void add(fraction const &f2)  { 
        
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

    const fraction f3;//or fraction const f1(10,2) => constant object of fraction class

    //f3 is constant object so only those function which
    // are not changing any data member of that object and 
    //on that function const keyword is use only that function can be called

     cout<<f3.getNumerator()<<" "<<f3.getDenumerator()<<endl; //can be called as getNumerator and getdenomentor
                                                          // only return value not make changes
     f3.print(); //can be called as it not changing any value

    // f3.setDenominator(10); cannot be called this function is changing th value
}