#include <iostream>
#include <vector>
using namespace std;

int sum = 0;
void merge(vector<int> &arr, int L, int M, int R);
void mergeSort(vector<int> &arr, int L, int R)
{
    if (L == R)
        return;
    int mid = L + ((R - L) >> 1);
    mergeSort(arr, L, mid);
    mergeSort(arr, mid + 1, R);
    merge(arr, L, mid, R);
}

void merge(vector<int> &arr, int L, int M, int R)
{
    vector<int> help(R - L + 1);
    int p1 = L;
    int p2 = M + 1;
    int i = 0;
    while (p1 <= M && p2 <= R)
    {
        // help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
        if (arr[p1] < arr[p2])
        {
            sum += (R - p2 + 1) * arr[p1];
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

void printArray(const vector<int> &arr)
{
    cout << endl;
    for (int i : arr)
    {
        cout << i << ", ";
    }
    cout << endl;
}

int main()
{
    vector<int> a = {1, 3, 4, 2, 5};
    mergeSort(a, 0, 4);
    cout << sum << endl;
    return 0;
}
