#include <iostream>
#include <vector>

using namespace std;

void merge(vector<size_t>& arr, size_t left, size_t mid, size_t right, size_t& comparisons, size_t& swaps)
{
    size_t sub_arr_left = mid - left + 1;
    size_t sub_arr_right = right - mid;

    vector<int> left_arr(sub_arr_left);
    vector<int> right_arr(sub_arr_right);

    for (int i = 0; i < sub_arr_left; i++)
    {
        ++swaps;
        left_arr[i] = arr[left + i];
    }

    for (int j = 0; j < sub_arr_right; j++)
    {
        ++swaps;
        right_arr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < sub_arr_left && j < sub_arr_right) 
    {
        ++comparisons;
        if (left_arr[i] <= right_arr[j]) 
        {
            ++swaps;
            arr[k] = left_arr[i];
            i++;
        }
        else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < sub_arr_left) 
    {
        ++swaps;
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < sub_arr_right) 
    {
        ++swaps;
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

void merge_sort(vector<size_t>& arr, size_t left, size_t right, size_t& comparisons, size_t& swaps)
{
    if (left >= right)
        return;
        
    size_t mid = left + (right - left) / 2;

    merge_sort(arr, left, mid, comparisons, swaps);
    merge_sort(arr, mid + 1, right, comparisons, swaps);
    merge(arr, left, mid, right, comparisons, swaps);
    
}
void sort_merge_wrap(vector<size_t>& arr, size_t& comparisons, size_t& swaps)
{
    comparisons = 0;
    swaps = 0;
    merge_sort(arr, 0, arr.size() - 1, comparisons, swaps);
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

int main() 
{
    cout << "Merge sort:" << endl;
    sorting(sort_merge_wrap);

    return 0;
}
