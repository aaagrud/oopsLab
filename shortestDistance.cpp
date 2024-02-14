/*
Write a program to find shortest distance between three coordinate points representing vertices of a triangle using inline function. Also check validity of sides to make a triangle.
*/

#include<iostream>
#include<cmath>
using namespace std;

class triangle{
    float x1, y1, x2, y2, x3, y3;
    float a, b, c;

    public:

        void assign(){
            cout << "enter x1, y1: ";
            cin >> x1 >> y1;
            cout << "enter x2, y2: ";
            cin >> x2 >> y2;
            cout << "enter x3, y3: ";
            cin >> x3 >> y3;
        }

        void shortestDistance(){
            a = pow(pow(x2 - x1, 2) + pow(y2 - y1, 2), 0.5); 
            b = pow(pow(x3 - x2, 2) + pow(y3 - y2, 2), 0.5);
            c = pow(pow(x1 - x3, 2) + pow(y1 - y3, 2), 0.5);
            cout << "the distances are: \n";
            cout << "between x1 and x2: " << a << "\n";
            cout << "between x2 and x3: " << b << "\n";
            cout << "between x3 and x1: " << c << "\n";
        }

        void valid(){
            if(a + b > c && b + c > a && c + a > b){
                cout << "the triangle is invalid";
            }
            else{
                cout << "the triangle is valid";
            }
        }
};

int main(){
    triangle a;
    a.assign();
    a.shortestDistance();
    a.valid();
}
