#include <iostream>
#include <vector>

using namespace std;

void sort_simple_insertion(vector<size_t>& arr, size_t& comparisons, size_t& swaps)
{
    comparisons = 0;
    swaps = 0;
    if (arr.empty())
        return;

    for (size_t i = 1; i < arr.size(); i++) 
    {
        size_t key = arr[i];
        size_t j = i - 1;

        while (j < arr.size() && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            ++swaps;
            j--;
        }

        arr[j + 1] = key;
        ++swaps;
    }
    comparisons = 0;
}


void sort_simple_bubble(vector<size_t>& arr, size_t& comparisons, size_t& swaps) 
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = 0; j < arr.size() - i - 1; j++) 
        {
            ++comparisons;
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);
                ++swaps;
            }
        }
    }
}

void sort_simple_selection(vector<size_t>& arr, size_t& comparisons, size_t& swaps) 
{
    comparisons = 0;
    swaps = 0;
    if (arr.empty())
        return;

    for (int i = 0; i < arr.size() - 1; i++) 
    {
        int min_index = i;
        for (int j = i + 1; j < arr.size(); j++) 
        {
            ++comparisons;
            if (arr[j] < arr[min_index]) 
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
        ++swaps;
    }
}



vector<size_t> createArr(const size_t n, const bool ordered)
{
    vector<size_t> arr = vector<size_t>();
    if (ordered)
    {
        for (size_t i = n; i > 0; --i)
        {
            arr.push_back(i);
        }
    }
    else
    {
        for (size_t i = 1; i <= n; ++i)
        {
            arr.push_back(i);
        }
    }
    return arr;
}

void sortingOutput(void (*func)(vector<size_t>& arr, size_t& comparisons, size_t& swaps), vector<size_t> arr)
{
    size_t comparisons = 0;
    size_t swaps = 0;
    func(arr, comparisons, swaps);
    cout << "\t- Size: " << arr.size() << endl;
    cout << "\t- Comparisons: " << comparisons << endl;
    cout << "\t- Swaps: " << swaps << endl;
    cout << "\n";
}

void sorting(void (*func)(vector<size_t>& arr, size_t& comparisons, size_t& swaps))
{
    cout << "- Best cases:" << endl;
    for (size_t i = 100; i <= 1000000; i *= 10)
    {
        sortingOutput(func, createArr(i, false));
    }
    cout << "- Worst cases:" << endl;
    for (size_t i = 100; i <= 1000000; i *= 10)
    {
        sortingOutput(func, createArr(i, true));
    }
}

void main()
{
    cout << "Simple Insertion:" << endl;
    sorting(sort_simple_insertion);
    cout << "Simple Bubble:" << endl;
    sorting(sort_simple_bubble);
    cout << "Simple Selection:" << endl;
    sorting(sort_simple_selection);
}