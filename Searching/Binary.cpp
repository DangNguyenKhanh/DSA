TÌM KIẾM NHỊ PHÂN
- Bắt buộc mảng phải được sắp xếp trước
- Time complexity = O(log2|n)
  

#include<iostream>
using namespace std;

int BinarySearch(int a[], int n, int key)
{
    int index = -1;
    int i = 0;
    int j = n - 1;
    while(i <= j)
    {
        int k = (i + j) / 2;
        if(key < a[k])
            j = k - 1;
        else if(key == a[k])
        {
            index = k;
            break;
        }
        else
            i = k + 1;
    }
    return index;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 10, 12};
    int n = sizeof(a) / sizeof(int);
    cout << BinarySearch(a, n, 5) << endl;
}

