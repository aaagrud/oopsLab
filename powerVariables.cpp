/*
Write a program to calculate the power of variables for calculating concept of function overloading.
*/

#include<iostream>
#include<cmath>
using namespace std;

int power(int a, int b){
    return pow(a, b);
}

float power(float a, float b){
    return pow(a, b);
}

int main(){
    int m, n;
    cout << "enter integer values: ";
    cin >> m >> n;
    cout << "the power is: " << power(m, n);
    float x, y;
    cout << "\nenter float values: ";
    cin >> x >> y;
    cout << "the power is: " << power(x, y);
    
}
