#include<iostream>
using namespace std;

unsigned long long Factorial(int n)
{
    if(n == 0)
        return 1;
    return n * Factorial(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << Factorial(n) << endl;
}

