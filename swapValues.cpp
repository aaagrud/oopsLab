/*
Write a program to swap the values of two objects of the same class to demonstrate call by value, call by address and call by reference.
*/

#include<iostream>
using namespace std;

class swappy{
    public:
    
    int data;
    void assign(){
        cout << "enter a: ";
        cin >> data;
    }  

    void display(){
        cout << "data: " << data << "\n";
    }
    
    void swapAddress(swappy *m, swappy *n){
        int temp;
        temp = m->data;
        m->data = n->data;
        n->data = temp;
    }

    void swapReference(swappy &m, swappy &n){
        int temp;
        temp = m.data;
        m.data = n.data;
        n.data = temp;
    }

    void swapValue(swappy m, swappy n){
        int temp;
        temp = m.data;
        m.data = n.data;
        n.data = temp;
    }
};

int main(){
    swappy a;
    swappy b;
    a.assign();
    b.assign();
    cout << "original values\n";
    cout << "a: " << a.data << ", b: " << b.data << "\n";
    a.swapValue(a, b);
    cout << "swapped by value:\n";
    cout << "a: " << a.data << ", b: " << b.data << "\n";
    a.swapReference(a, b);
    cout << "swapped by reference: \n";
    cout << "a: " << a.data << ", b: " << b.data << "\n";
    a.swapAddress(&a, &b);
    cout << "swapped by address: \n";
    cout << "a: " << a.data << ", b: " << b.data << "\n";
}
