/*
Polar coordinates are represented in angle and radius format while rectangular coordinates are (x, y).
Define classes for both and member function to convert from polar to rectangular coordinates.
*/

#include<iostream>
#include<cmath>
using namespace std;

class polar; 

class rectangular{
    float x, y;

public:
    rectangular(){}

    rectangular(polar &p);

    void assign(){
        cout << "enter x and y: ";
        cin >> x >> y;
    }

    friend class polar;

    void display(){
        cout << "(" << x << ", " << y << ")\n";
    }
};

class polar{
    float radius, theta;

public:
    polar(){}

    polar(rectangular &r);

    void assign(){
        cout << "enter radius and theta (in degrees): ";
        cin >> radius >> theta;
        theta = theta * M_PI / 180.0; 
    }

    void display(){
        cout << "\n" << radius << "(" << theta * 180.0 / M_PI << " degrees)\n";
    }

    friend class rectangular;
};

rectangular::rectangular(polar &p){
    x = p.radius * cos(p.theta);
    y = p.radius * sin(p.theta);
}

polar::polar(rectangular &r){
    radius = sqrt(r.x*r.x + r.y*r.y);
    theta = atan2(r.y, r.x);
}

int main() {
    polar p;
    p.assign();
    p.display();

    rectangular r(p);
    r.display();

    return 0;
}
