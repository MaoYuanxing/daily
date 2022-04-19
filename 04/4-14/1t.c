#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;
long long root(int B, int A, int n)
{
    cout << A << " :: " << B << endl;
    int a = B * sqrt(B * B - 4 * A) / 2;
    int b = B - a;
    cout << a << " :: " << b << endl;
    return pow(a, n) + pow(b, n);
}

int main()
{
    char s[] = "a\\b\\c";
    char *p;
    const char *delim = "\\";
    p = strtok(s, delim);
    while (p)
    {
        cout << p << endl;
        p = strtok(NULL, delim);
    }

    return 0;
}