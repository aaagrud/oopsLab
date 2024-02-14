/*
Write program to create class student with age, number and register number. Using inheritance, derive two classes M.Tech and B.Tech student. List both catagory of student in the increasing order of marks (B.Tech) and gpa (M.Tech). In case of tie, display whichever name comes first. Make sort function virtual.
*/

#include <iostream>
using namespace std;

class Student {
protected:
    string name;
    int age;
    int regNumber;
public:
    virtual void getData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter register number: ";
        cin >> regNumber;
    }
    virtual void displayData() {
        cout << "Name: " << name << ", Age: " << age << ", Register Number: " << regNumber;
    }
    virtual float getSortValue() const = 0;
    virtual ~Student() {}
    virtual bool operator<(const Student& other) const {
        return getSortValue() < other.getSortValue();
    }
};

class BTechStudent : public Student {
private:
    float marks;
public:
    void getData() override {
        Student::getData();
        cout << "Enter marks: ";
        cin >> marks;
    }
    void displayData() override {
        Student::displayData();
        cout << ", Marks: " << marks << endl;
    }
    float getSortValue() const override {
        return marks;
    }
};

class MTechStudent : public Student {
private:
    float gpa;
public:
    void getData() override {
        Student::getData();
        cout << "Enter GPA: ";
        cin >> gpa;
    }
    void displayData() override {
        Student::displayData();
        cout << ", GPA: " << gpa << endl;
    }
    float getSortValue() const override {
        return gpa;
    }
};

int main() {
    int n = 0;
    Student* students[100];

    while (true) {
        cout << "\n1. Add BTech Student\n2. Add MTech Student\n3. Display Sorted List\n4. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                if (n < 100) {
                    students[n] = new BTechStudent();
                    students[n]->getData();
                    n++;
                } else {
                    cout << "Maximum limit reached!\n";
                }
                break;
            case 2:
                if (n < 100) {
                    students[n] = new MTechStudent();
                    students[n]->getData();
                    n++;
                } else {
                    cout << "Maximum limit reached!\n";
                }
                break;
            case 3:
                for (int i = 0; i < n - 1; ++i) {
                    for (int j = 0; j < n - i - 1; ++j) {
                        if (*students[j + 1] < *students[j]) {
                            swap(students[j], students[j + 1]);
                        }
                    }
                }

                cout << "Sorted list of students:" << endl;
                for (int i = 0; i < n; ++i) {
                    students[i]->displayData();
                }
                break;
            case 4:
                for (int i = 0; i < n; ++i) {
                    delete students[i];
                }
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}
