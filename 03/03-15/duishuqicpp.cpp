#include "duishuqicpp.h"
#include <vector>
#include <cstdlib>
using namespace std;
vector<int> randomArray(int maxLen, int maxValue)
{

    int len = rand() % maxLen;
    vector<int> arr(len);
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand() % maxValue;
    }
    return arr;
}

//检查数组是否排列好顺序
bool isSorted(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}
