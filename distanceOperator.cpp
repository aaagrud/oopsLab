/*
Distance is measured in feet and inches unit. Overload operator + for adding two distances and < for comparing two distances. One of the functions should be a friend function.
*/

#include<iostream>
using namespace std;

class dist{
    int feet;
    int inches;

    public:

        void assign(){
            cout << "enter feet and inches: ";
            cin >> feet >> inches;
        }

        void display(){
            cout << "\n" << feet << " feets and " << inches << " inches";
        }

        dist operator +(dist d){
            dist temp;
            int totalInches = (12 * feet + inches) + (12 * d.feet + d.inches);
            temp.feet = totalInches / 12;
            temp.inches = totalInches % 12;
            return temp;
        }

        void operator <(dist d){
            int thisTotalInches = inches + (12 * feet);
            int thatTotalInches = d.inches + (12 * d.feet);
            if(thisTotalInches > thatTotalInches){
                cout << "\n" << feet << " feets " << inches << " inches is greater than " << d.feet << " feets " << d.inches << " inches.";
            }
            else if(thisTotalInches == thatTotalInches){
                cout << "\n" << feet << " feets " << inches << " inches is equal to " << d.feet << " feets " << d.inches << " inches.";
            }
            else{
                cout << "\n" << feet << " feets " << inches << " inches is less than " << d.feet << " feets " << d.inches << " inches.";
            }
        }

};

int main(){
    dist a, b, sum;
    a.assign();
    b.assign();
    sum = a + b;
    sum.display();
    a < b;
}
