/*
A phone number such as (212)767-8900, can be thought of as having three parents: the area code(212), the exchange 767, and the number 8900.
Write a C++ program that uses a structure to store these three parts of a phone number seperately. Call the structure phone. Create two structure variables of type two. Initialize one and have the user input a number for the other one. Then display both numbers.
*/

#include<iostream>
using namespace std;

struct phoneNumber{
    int areaCode;
    int exchange;
    int number;
};

int main(){
    phoneNumber phoneOne, phoneTwo;
    phoneOne.areaCode = 212;
    phoneOne.exchange = 767;
    phoneOne.number = 8900;
    cout << "(" << phoneOne.areaCode << ")" << phoneOne.exchange << "-" << phoneOne.number << "\n";
    cout << "enter area code, exchange and number: ";
    cin >> phoneTwo.areaCode >> phoneTwo.exchange >> phoneTwo.number;
    cout << "(" << phoneTwo.areaCode << ")" << phoneTwo.exchange << "-" << phoneTwo.number;
}
