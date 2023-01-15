Greatest Common Divisor - ước chung lớn nhất

#include<iostream>
using namespace std;

int GCD(int a, int b)
{
    while(b != 0)
    {
        if(a > b)
            a = a - b;
        else   
            b = b - a;
    }
    return a;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << GCD(a, b) << endl;
}


PSEUDOCODE

input a, b;
while (b != 0)
    if (a > b)
        a = a - b;
    else
        b = b - a;
output a;
