#include"Header.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> arr(size);

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < size; i++) 
    {
        cin >> arr[i];
    }
    //Heap sort
    heapSort(arr, size);
    cout << "Sorted array (Heap sort): "<< endl;;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    //Quick sort
    quickSort(arr, 0, size - 1);
    cout << "Sorted array (Quick sort):" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
