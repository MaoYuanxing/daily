#include <iostream>
#include <vector>
using namespace std;
int oddNum(vector<int> arr)
{
    int eor = 0;
    for (int i : arr)
    {
        eor ^= i;
    }
    return eor;
}
int main()
{
    vector<int> arr(5, 1);
    arr[3] = 3;
    cout << oddNum(arr) << endl;
    return 0;
}