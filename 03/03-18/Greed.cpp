#include <iostream>
#include <stack>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;

class test
{
    int **a;

public:
    test()
    {
        a = new int *[26];
    }
    ~test()
    {
        delete[] a;
    }
    void print()
    {
        for (int i = 0; i < 26; i++)
        {
            if (!a[i])
                cout << 1 << " , ";
        }
        cout << endl;
    }
};

int main()
{
    test a;
    a.print();
    return 0;
}