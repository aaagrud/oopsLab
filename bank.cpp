/*
Define a class to represent a bank account. Include numbers like depositor number, account number, account type, balance and depositor name. Write a C++ program with member functions to:
1. assign initial values
2. to deposit into an account
3. to withdraw an amount
4. to display
*/

#include<iostream>
using namespace std;

class bank{
    int number;
    int min;
    string name;
    string type;
    int balance;

    public:

    void assign(int x){
        cout << "enter name, type and initial deposit: ";
        cin >> name >> type >> balance;
        if(type == "savings"){
            min = 3000;
        }
        else{
            min = 1500;
        }
        number = x;
        for(int j = 0; j < 2; j++){
            if(balance >= min){
                cout << "\nyour account is number is: " << number;
                break;
            }
            else{
                cout << "insufficient initial deposit. try again. (try " << j + 1 << "/2)\nenter balance again: ";
                cin >> balance;
            }
        }
    }

    void deposit(){
        int amount;
        cout << "enter amount: ";
        cin >> amount;
        number = number + amount;
        cout << "amount deposited.\n";
    }
    
    void withdraw(){
        cout << "enter amount: ";
        int amount;
        cin >> amount;
        if(balance - amount > min){
            cout << "amount withdrawn.\n";
            balance = balance - amount;
        }
        else{
            cout << "insufficient balance.\n";
        }
    }

    void display(){
        cout << "number: " << number << "\n";
        cout << "name: " << name << "\n";
        cout << "type: " << type << "\n";
        cout << "balance: " << balance << "\n";
    }
};

int main(){
    bank b[100];
    int i = 0;
    int option, choice;
    do{
        cout << "BANK\n1. assign values\n2. deposit\n3. withdraw\n4. display\nenter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                b[i].assign(i);
                i = i + 1;
                break;
            case 2:
                int n;
                cout << "\nenter your account number: ";
                cin >> n;
                b[n].deposit();
                break;
            case 3:
                cout << "\nenter your account number: ";
                cin >> n;
                b[n].withdraw();
                break;
            case 4:
                cout << "\nenter your account number: ";
                cin >> n;
                b[n].display();
                break;
        }
        cout << "\nenter 1 to continue: ";
        cin >> option;
    }while (option == 1);
}
