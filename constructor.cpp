//constructor overloading
#include<iostream>
using namespace std;
class Complex{
    int a,b;
    public:
        Complex(int x,int y){
            x =a;
            y = b;
        }
        Complex(int x){
            a= x;
            b=0;
        }
        Complex(){
            a=0;
            b=0;
        }

        void printNumber()
        {
            cout<<"Your number is"<<a<<" + "<<b<<"i"<<endl;
        }
};
int main(){
Complex c1(4,5);
c1.printNumber();

Complex c2(4,5);
c2.printNumber();
Complex c3(4,5);
c3.printNumber();
}