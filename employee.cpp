/*
Write program where class employee class contains details like name, employee number, pay rate, constructor function and pay() function.

Manager class inherits from employee and has the option of drawing pay on hourly or salary basis and has an additional data isSalaried(bool).

Supervisor class is always salaried and has additional field department. Base and both derived classes should contain pay() function with same same.
*/

#include<iostream>
using namespace std;

class employee{
    protected:
        string name;
        int number, payRate;
    
    public:
        employee(){}

        employee(int n){
            number = n;
            cout << "enter name and pay rate: ";
            cin >> name >> payRate;
        }

        virtual void pay(){
            cout << "paid amount: " << payRate;
        }
};

class manager: public employee{
    bool isSalaried;

    public:

        void assign(int x){
            cout << "enter name and payrate: ";
            cin >> name >> payRate;
            int m;
            cout << "enter 1 if salaried: ";
            cin >> m;
            if(m == 1){
                isSalaried = true;
            }
            else{
                isSalaried = false;
            }
            number = x;
            cout << "employee number is: " << number;
        }

        void pay(){
            if(isSalaried){
                cout << "\npaid rupees: " << payRate;
            }
            else{
                cout << "\nenter hours of work: ";
                int h;
                cin >> h;
                cout << "paid rupees: " << payRate * h;
            }
        }
};

class supervisor: public employee{
    string department;

    public:
        void assign(int x){
            cout << "\nenter name, department and payrate: ";
            cin >> name >> payRate >> department;
            number = x;
            cout << "employee number is: " << number;
        }

        void pay(){
            cout << "\npaid rupees: " << payRate;
        }
};

int main(){
    int choice, option = 1;
    manager m[100]; int i = 0;
    supervisor s[100]; int j = 0;
    do{
        cout << "\n1. add manager\n2. add supervisor\n3. pay manager\n4. pay supervisor\nenter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
            m[i].assign(i);
            i = i + 1;
            break;

            case 2:
            s[j].assign(j);
            j = j + 1;
            break;

            case 3:
            cout << "enter employee number: ";
            int n;
            cin >> n;
            m[n].pay();
            break;

            case 4:
            cout << "enter employee number: ";
            cin >> n;
            s[n].pay();
            break;
        }
        cout << "\nenter 1 to continue: ";
        cin >> option;
    }while(option == 1);
}
