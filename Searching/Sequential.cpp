TÌM KIẾM TUẦN TỰ 

#include<iostream>
using namespace std;

int SequentialSearch(int a[], bool sorted, int n, int key)
{
    int index = -1;
    int i = 0;
    if(!sorted)
    {
        while(i < n)
            if(a[i] == key)
            {
                index = i;
                break;
            }
            else
                i++;
    }
    else
    {
        while(i < n)
            if(a[i] < key)
                i++;
            else if(a[i] == key)
            {
                index = i;
                break;
            }
            else
                i = n;
    }
    return index;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 10, 6};
    int n = sizeof(a) / sizeof(int);
    cout << SequentialSearch(a, false, n, 10) << endl;
    int b[] = {1, 2, 3, 4, 5, 10, 12};
    cout << SequentialSearch(b, true, n, 10) << endl;
}
