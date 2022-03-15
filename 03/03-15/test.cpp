#include <iostream>
#include <vector>
#include <array>
#include <limits.h>
#include <duishuqicpp.h>
#include <algorithm>
using namespace std;
int maxbits(vector<int> &arr)
{
    int max = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    int res = 0;
    while (max != 0)
    {
        max /= 10;
        res++;
    }
    return res;
}

int getDigit(int num, int d)
{
    int res = 0;
    while (--d)
    {
        num /= 10;
    }
    res = num % 10;
    return res;
}

void radixSort(vector<int> &arr, int L, int R, int digit)
{
    int radix = 10;
    int i = 0, j = 0;
    //有几个数准备几个辅助空间
    vector<int> bucket = vector<int>(arr.size());
    for (int d = 1; d <= digit; d++)
    { //有几位就进出几次
        // 10个空间
        // count[0]d位为零的有几个数
        // count[1]d位为0，1的有几个数
        // count[i]d位为0~i的有几个数
        array<int, 10> count{};
        for (i = L; i <= R; i++)
        {
            j = getDigit(arr[i], d);
            count[j]++;
        }
        for (i = 1; i < radix; i++)
        {
            count[i] = count[i] + count[i - 1];
        }
        for (i = R; i >= L; i--)
        {
            j = getDigit(arr[i], d);
            bucket[--count[j]] = arr[i];
        }
        for (i = L, j = 0; i <= R; i++, j++)
        {
            arr[i] = bucket[j];
        }
    }
}

void radixSort(vector<int> &arr)
{
    int n = arr.size();
    if (n < 2)
        return;
    radixSort(arr, 0, n - 1, maxbits(arr));
}

void print(const vector<int> &arr)
{
    cout << endl;
    for (int i : arr)
    {
        cout << i << ", ";
    }
    cout << endl;
    cout << endl;
}

int main()
{
    vector<int> arr = randomArray(10, 100000);
    print(arr);
    radixSort(arr);
    print(arr);
    vector<int> myvec{3, 2, 5, 7, 3, 2};
    vector<int> lbvec(myvec);
    sort(lbvec.begin(), lbvec.end(), [](int a, int b) -> bool
         { return a < b; }); // Lambda表达式
    cout << "lambda expression:" << endl;
    for (int it : lbvec)
        cout << it << ' ';
    cout << endl;
    return 0;
}