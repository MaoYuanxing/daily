#include <iostream>
#include <vector>
using namespace std;

class heap
{
    int heapSize;
    vector<int> arr;
    void swap(int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    void heapInsert(/*vector<int> &arr,*/ int index)
    {
        while (arr[index] > arr[(index - 1) / 2])
        {
            swap(index, (index - 1) / 2);
            index = (index - 1) / 2;
        }
    }
    void heapify(/*vector<int> &arr,*/ int index, int heapSize)
    {
        int left = index * 2 + 1; // left child
        while (left < heapSize)
        { // whether left child belongs to heap
            // define largest get the index of the bigger one
            int largest = left + 1 < heapSize && arr[left + 1] > arr[left] ? left + 1 : left;
            // largest get the index of the bigger one between father and largest child
            largest = arr[largest] > arr[index] ? largest : index;
            // if largest == index means father is the biggest one then don't need to move
            if (largest == index)
                break;
            // father go down;
            swap(largest, index);
            index = largest;
            left = index * 2 + 1;
        }
    }

public:
    heap(vector<int> &arr) : heapSize(0), arr(arr)
    {
    }

    void add(int val)
    {
        if (heapSize + 1 > arr.size())
            arr.resize(2 * heapSize);
        arr[heapSize] = val;
        heapInsert(heapSize++);
    }
    int pop()
    {
        int ans = arr[0];
        arr[0] = arr[heapSize - 1];
        heapify(0, heapSize--);
        return ans;
    }
    void print()
    {
        cout << endl;
        for (int i : arr)
        {
            cout << i << ", ";
        }
        cout << endl;
    }
};

int main()
{
    vector<int> arr = {3, 5, 9, 4, 6, 7, 0};
    heap s(arr);
    for (int i : arr)
    {
        s.add(i);
    }
    s.print();
    s.add(5);
    s.add(13);
    s.add(3);
    s.print();
    return 0;
}