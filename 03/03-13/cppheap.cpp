#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    srand((unsigned int)time(0));
    priority_queue<int, vector<int>, greater<int>> a;
    for (int i = 0; i < 8; i++)
    {
        a.emplace(rand() % 8);
    }
    cout << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << a.top() << ", ";
        a.pop();
    }
    cout << endl;
    cout << endl;
    return 0;
}