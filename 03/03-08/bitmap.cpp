#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// a + b  (a ^ b)无进位相加信息  ((a & b) << 1) 进位信息
int add(int a, int b)
{
    int sum = 0;
    while (b != 0)
    {
        sum = a ^ b;
        b = ((a & b) << 1);
        a = sum;
    }
    return sum;
}

// a - b = a + (-b); -b = ~b + 1 = add(~b, 1)
int subtract(int a, int b)
{
    return add(a, add(~b, 1));
}

// a * b
int muti(int a, int b)
{
    int res = 0;
    while (b != 0)
    {
        if ((b & 1) != 0)
        {
            res = add(res, a);
        }
        a <<= 1;
        b = (unsigned int)b >> 1;
    }
    return res;
}

// a / b
bool isNeg(int n)
{
    return n < 0;
}
int negNum(int n)
{
    return add(~n, 1);
}
int Div(int a, int b)
{
    int x = isNeg(a) ? negNum(a) : a;
    int y = isNeg(b) ? negNum(b) : b;
    int res = 0;
    // x/y
    for (int i = 30; i >= 0; i--)
    { //移动30位是因为x是正数极端情况为x = 010000……移动30位就使得1到最左了
        if ((x >> i) >= y)
        { //使x右移而不左移y是因为当x很大时如x = 011...时y可能会左移到符号位发生未知错误
            res |= (1 << i);
            x = subtract(x, (x >> i));
        }
    }

    return isNeg(a) ^ isNeg(b) ? negNum(res) : res;
}

int divide(int a, int b)
{
    if (a == INT_MIN && b == INT_MIN)
    {
        return 1;
    }
    else if (b == INT_MIN)
    {
        return 0;
    }
    else if (a == INT_MIN)
    {
        if (b == negNum(1))
            return INT_MAX;
        int res = Div(add(a, 1), b);
        return add(res, Div(subtract(a, muti(res, b)), b));
    }
    else
    {
        return Div(a, b);
    }
}

int ArrSize(int max)
{
    return (max + 32) >> 5;
}
void add(int num, vector<int> &bit)
{
    bit[num >> 5] |= 1 << (num & 31);
}
void Delete(int num, vector<int> bit)
{
    bit[num >> 5] &= ~(1 << (num & 31));
}
bool contains(int num, vector<int> bit)
{
    return (bit[num >> 5] & (1 << (num & 31))) != 0;
}

int main()
{
    // int max = ArrSize(1023);
    // vector<int> bit(max);
    // add(170, bit);
    // if (contains(170, bit))
    // {
    //     cout << "add successfully!" << endl;
    // }
    // else
    // {
    //     cout << "error" << endl;
    // }

    int a = 3;
    int b = 6;
    cout << add(a, b) << " " << subtract(a, b) << " " << muti(a, -1) << " ";
    cout << divide(INT_MIN, 66) << " " << endl;
    // cout << INT_MIN << " " << -INT_MIN << endl;
    return 0;
}