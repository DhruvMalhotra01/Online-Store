#include<iostream>
using namespace std;
// a constructor is a special member function with same name as of a class.
// it is used to initalize the object of its class
//it is automatic invoked
class Complex{
    int a,b;
    public:
        Complex(int,int);

        void printNumber(){
            cout<<"Your number is "<<a<<" + "<<b<<" i"<<endl;
        }
};
Complex :: Complex(int x, int y)
{
    a = x;
    b = y;
}
int main(){    
    Complex a(4,6);
    Complex b = Complex(5, 7);
    a.printNumber();
    b.printNumber();
}