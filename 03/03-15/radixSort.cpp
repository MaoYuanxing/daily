#include <iostream>
#include <duishuqicpp.h>
#include <vector>
#include <array>
#include <limits.h>
using namespace std;

class RadixSort
{
    vector<int> arr;

public:
    RadixSort(vector<int> arr) : arr(arr) {}
    void radixSort()
    {
        int n = arr.size();
        if (n < 2)
            return;
        radixSort(arr, 0, n - 1, maxbits(arr));
    }
    void print()
    {
        cout << endl;
        for (int i : arr)
        {
            cout << i << ", ";
        }
        cout << endl;
        cout << endl;
    }

private:
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
            array<int, 10> count;
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
                bucket[count[j] - 1] = arr[i];
                count[j]--;
            }
            for (i = L, j = 0; i <= R; i++, j++)
            {
                arr[i] = bucket[j];
            }
        }
    }
};

int main()
{
    RadixSort a({1, 3, 5, 2, 6});
    a.print();
    a.radixSort();
    a.print();
    return 0;
}