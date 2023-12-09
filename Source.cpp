#include"Header.h"
#include <iostream>
#include <vector>


void heapS(vector<int>& arr, int size, int i)
{
    int largest = i;

    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < size && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapS(arr, size, largest);
    }
}

void heapSort(vector<int>& arr, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapS(arr, size, i);

    for (int i = size - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapS(arr, i, 0);
    }
}


void quickSort(vector<int>& numbers, int left, int right)
{
    int pivot;
    int l_hold = left;
    int r_hold = right;
    pivot = numbers[left];
    while (left < right)
    {
        while ((numbers[right] >= pivot) && (left < right))
        {
            right--;
        }
        if (left != right)
        {
            numbers[left] = numbers[right];
            left++;
        }
        while ((numbers[left] <= pivot) && (left < right))
        {
            left++;
        }
        if (left != right)
        {
            numbers[right] = numbers[left];
            right--;
        }
    }
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
    {
        quickSort(numbers, left, pivot - 1);
    }
    if (right > pivot)
    {
        quickSort(numbers, pivot + 1, right);
    }
}