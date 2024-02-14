/*
Define a class Date that contains details like year, month and date. Write a C++ program to check the validity of the date that you enter and display the next date.
*/

#include<iostream>
using namespace std;

class date{
    int year;
    int month;
    int day;

    public:

    void assign(){
        cout << "enter date, month and year: ";
        cin >> day >> month >> year;
        cout << "date inputted\n";
    }

    void display(){
        cout << day << "/" << month << "/" << year << "\n";
        if(valid()){
            cout << "the date is valid.\n";
        }
        else{
            cout << "the date is invalid.\n";
        }
    }

    bool leap(){
        if(year % 4 == 0){
            if(year % 100 != 0 || year % 400 == 0){
                return true;
            }
        }
        return false;
    }

    void nextDate(){
        day = day + 1;
        if(valid()){
            cout << "the next date is: ";
            display();
        }
        else{
            day = 1;
            month = month + 1;
            if(valid()){
                cout << "the next date is: ";
                display();
            }
            else{
                month = 1;
                year = year + 1;
                cout << "the next date is: ";
                display();
            }
        }
    }

    bool valid() {
        if (year < 0) {
            return false;
        }
        if (month <= 0 || month > 12) {
            return false;
        }
        if (day <= 0) {
            return false;
        }
        if (month == 2) {
            if (leap()) {
                return day <= 29;
            } else {
                return day <= 28;
            }
        }
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            return day <= 30;
        }
        return day <= 31;
    }
};

int main(){
    date d;
    d.assign();
    d.display();
    d.valid();
    d.nextDate();
}
