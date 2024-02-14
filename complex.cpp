/*
Write a program using operator overloading to overload stream operators (<< and >>) to read and display objects of complex.
*/

#include<iostream>
using namespace std;

class complex{
    int real, img;

    public:

        void assign(){
            cout << "enter real and imaginary parts: ";
            cin >> real >> img;
        }

        void display(){
            cout << real << " + " << img << "i";
        }

        friend ostream& operator <<(ostream &out, complex &c);

        friend istream& operator >>(istream &in, complex &c);
};

ostream& operator <<(ostream &out, complex &c){
    out << c.real << " + " << c.img << "i";
    return out;
}

istream& operator >>(istream &in, complex &c){
    cout << "enter real and imaginary parts: ";
    in >> c.real >> c.img;
    return in;
}

int main(){
    complex c;
    cin >> c;
    cout << c;
}
