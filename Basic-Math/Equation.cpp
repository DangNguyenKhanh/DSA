#include<iostream>
#include<cmath>
using namespace std;

// ax + b = 0 -> find x
void EquationD1(double a, double b)
{
    if(a == 0 && b == 0)
        cout << "The equation has infinitely many solutions" << endl;
    else if(a == 0 && b != 0)
        cout << "The equation has no solutions" << endl;
    else
        cout << "The equation has solutions for x: " << ((-b / a == -0) ? 0 : -b / a) << endl;
}

// ax^2 + bx + c = 0 -> find x
void EquationD2(double a, double b, double c)
{
    double delta = b * b - 4 * a * c;
    if(delta < 0)
        cout << "The equation has no solutions" << endl;
    else if(delta == 0)
        cout << "The equation has one solutions for x: " << ((-b / (2 * a) == -0) ? 0 : -b / (2 * a)) << endl;
    else 
    {
        cout << "The equation has two solutions for x: " << endl;
        cout << "x1 = " << (-b - sqrt(delta)) / (2 * a) << endl;
        cout << "x2 = " << (-b + sqrt(delta)) / (2 * a) << endl;
    }
}

int main()
{
    // double a, b;
    // cin >> a >> b;
    // EquationD1(a, b);

    double a, b, c;
    cin >> a >> b >> c;
    EquationD2(a, b, c);
}
