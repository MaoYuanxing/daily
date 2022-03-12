#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void swap(int &i, int &j)
{
    if (i == j)
    {
        return;
    }
    i = i ^ j;
    j = i ^ j;
    i = i ^ j;
}

void testhelan(vector<int> &nums, int num)
{
    int idl = 0, idb = nums.size() - 1;
    for (int i = 0; i < idb; i++)
    {
        if (nums[i] < num)
        {
            swap(nums[i], nums[idl]);
            idl++;
        }
        if (nums[i] > num)
        {
            swap(nums[i], nums[idb]);
            idb--;
            i--;
        }
    }
}
void swap(vector<int> &arr, int L, int R)
{
    int temp = arr[L];
    arr[L] = arr[R];
    arr[R] = temp;
}
vector<int> partition(vector<int> &arr, int L, int R);
void quickSort(vector<int> &arr, int L, int R)
{
    if (L < R)
    {
        int i = rand() % (R - L + 1) + L;
        swap(arr, i, R);
        vector<int> p = partition(arr, L, R);
        quickSort(arr, L, p[0] - 1);
        quickSort(arr, p[1] + 1, R);
    }
}

vector<int> partition(vector<int> &arr, int L, int R)
{
    int less = L - 1;
    int more = R;
    while (L < more)
    {
        if (arr[L] < arr[R])
        {
            swap(arr, ++less, L++);
        }
        else if (arr[L] > arr[R])
        {
            swap(arr, --more, L);
        }
        else
        {
            L++;
        }
    }
    swap(arr, more, R);
    return {less + 1, more};
}

void printarray(const vector<int> &a)
{
    cout << endl;
    for (int i : a)
    {
        cout << i << ", ";
    }
    cout << endl;
    cout << endl;
}

int main()
{
    vector<int> a = {1, 23, 4, 35, 4, 2, 2, 1};
    printarray(a);
    testhelan(a, 4);
    printarray(a);
    quickSort(a, 0, a.size() - 1);
    printarray(a);
    return 0;
}