/*
Define a class for overloading the + operator such that it adds a particular number of days to a date so that it produces the new date.
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
        cout << "date inputted: ";
    }

    void display(){
        cout << day << "/" << month << "/" << year << "\n";
    }

    bool leap(){
        if(year % 4 == 0){
            if(year % 100 != 0 || year % 400 == 0){
                return true;
            }
        }
        return false;
    }

    void operator +(int x){
        for(int i = 0; i < x; i++){
            nextDate();
        }
        display();
    }

    void nextDate(){
        day = day + 1;
        if(valid()){
            cout << "";
        }
        else{
            day = 1;
            month = month + 1;
            if(valid()){
                cout << "";
            }
            else{
                month = 1;
                year = year + 1;
                cout << "";
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
    cout << "the next date: ";
    d.nextDate();
    d.display();
    cout << "the date after 50 days: ";
    d + 50;
}
