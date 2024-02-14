/*
Write an array which contains an integer array and static function to find the average of that array and other necessary functions. Create three objects. 
Read values into array using one object, and find average. Let second object modify the value by multiplying each element by a certain multiplier.
Repeat the process of finding the average using first object.
Using the third object arrange numbers in ascending order and print.
*/

#include<iostream>
using namespace std;

class array{
    static float a[];
    static int n;
    static float sum;

    public:

        void assign(){
            cout << "enter number of elements: ";
            cin >> n;
            for(int i = 0; i < n; i++){
                cout << "enter element: ";
                cin >> a[i];
            }
        }

        static float average(){
            sum = 0;
            for(int i = 0; i < n; i++){
                sum = sum + a[i];
            }
            return sum / n;
        }

        void multiplier(){
            int m;
            cout << "\nenter multiplier: ";
            cin >> m;
            for(int i = 0; i < n; i++){
                a[i] = a[i] * m;
            }
        }

        void display(){
            cout << "\nthe array is: ";
            for(int i = 0; i < n; i++){
                cout << a[i] << " ";
            }
            cout << "\n";
        }

        void sort(){
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    if(a[j] < a[i]){
                        int temp;
                        temp = a[j];
                        a[j] = a[i];
                        a[i] = temp;
                    }
                }
            }
        }
};

int array::n = 0;
float array::a[] = {0};
float array::sum = 0;



int main(){
    array a, b, c;
    a.assign();
    cout << "the average is: " << a.average();
    b.multiplier();
    cout << "multiplied!\n";
    cout << "the average is: " << a.average();
    c.sort();
    c.display();
}
