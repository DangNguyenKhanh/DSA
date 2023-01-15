#include<iostream>
using namespace std;

// 0 1 1 2 3 5 8
unsigned long long Fibonacci(int index)
{
    
    if(index <= 1) 
        return index;
    return Fibonacci(index - 1) + Fibonacci(index - 2);
}

int main()
{
    cout << Fibonacci(0) << endl;
}
