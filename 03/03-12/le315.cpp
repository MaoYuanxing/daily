#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
    vector<int> counts;
    vector<int> arr;
    unordered_map<int, int> hashs;
    void mergeSort(int L, int R)
    {
        if (L == R)
            return;
        int mid = L + ((R - L) >> 1);
        mergeSort(L, mid);
        mergeSort(mid + 1, R);
        merge(L, mid, R);
    }
    void merge(int L, int M, int R)
    {
        vector<int> help(R - L + 1);
        int p1 = L;
        int p2 = M + 1;
        int i = 0;
        while (p1 <= M && p2 <= R)
        {
            if (arr[p1] > arr[p2])
            {
                counts[hashs[arr[p1]]] += R - p2 + 1;
                help[i++] = arr[p1++];
            }
            else
            {
                help[i++] = arr[p2++];
            }
        }
        while (p1 <= M)
        {
            help[i++] = arr[p1++];
        }
        while (p2 <= R)
        {
            help[i++] = arr[p2++];
        }
        for (int i = 0; i < R - L + 1; i++)
        {
            arr[L + i] = help[i];
        }
    }

public:
    vector<int> countSmaller(vector<int> &nums)
    {
        arr = nums;
        counts = vector<int>(nums.size());
        mergeSort(0, nums.size() - 1);
        return counts;
    }
};

int main()
{
    vector<int> arr = {5, 2, 6, 1};
    Solution A;
    vector<int> counts = A.countSmaller(arr);
    for (int i : counts)
    {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}