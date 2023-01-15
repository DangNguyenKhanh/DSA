#include<iostream>
using namespace std;

// 1 1 2 3 5 8
// 0 1 2 3 4 5: index
unsigned long long Fibonacci(int index)
{
    if(index == 0 || index == 1) return 1;
    return Fibonacci(index - 1) + Fibonacci(index - 2);
}

int main()
{
    cout << Fibonacci(4) << endl;
}
