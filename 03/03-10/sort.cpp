#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;
void printArray(vector<int> arr)
{
    for (int i : arr)
    {
        cout << i << ", ";
    }
    cout << endl;
}

void swap(vector<int> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selectSort(vector<int> &arr)
{
    int n = arr.size();
    if (n < 2)
        return;
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minIndex] > arr[j])
                minIndex = j;
        }
        swap(arr, i, minIndex);
    }
}

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    if (n < 2)
        return;
    for (int i = n; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr, j, j + 1);
        }
    }
}

void insertSort(vector<int> &arr)
{
    int n = arr.size();
    if (n < 2)
        return;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
                swap(arr, j, j - 1);
        }
    }
}

int main()
{
    srand((unsigned)time(0));
    vector<int> arr;
    int n = 15;
    int maxValue = 100;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rand() % maxValue);
    }
    cout << endl;
    printArray(arr);
    insertSort(arr);
    printArray(arr);
}