/*
Distance is measured in feet and inches unit. Overload operator + for adding two distances and < for comparing two distances. One of the functions should be a friend function.
*/

#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

class dist{
    float feet = 0;
    float inches = 0;

    public:
        dist(){}

        dist(float meters){
            float totalInches = 39.3701 * meters;
            while(totalInches >= 12){
                feet = feet + 1;
                totalInches = totalInches - 12;
            }
            inches = totalInches;
        }

        operator float(){
            float totalInches;
            totalInches = (feet * 12 + inches);
            return totalInches / 39.3701;
        }

        void assign(){
            cout << "enter feet and inches: ";
            cin >> feet >> inches;
        }

        void display(){
            cout << "\n" << feet << " feets and " << inches << " inches";
        }
};

int main(){
    dist a;
    a.assign();
    float m = a;
    cout << "distance in meters: " << m;
    dist b = dist(m);
    cout << "\ndistance in feet and inches: ";
    b.display();
}
