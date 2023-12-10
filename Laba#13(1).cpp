#include <iostream>
#include <vector>

using namespace std;

int partition(vector<size_t>&arr, int low, int high, size_t& comparisons, size_t& swaps)
{
    size_t pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        ++comparisons;
        if (arr[j] <= pivot)
        {
            i++;
            ++swaps;
            swap(arr[i], arr[j]);
        }
    }
    ++swaps;
    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(vector<size_t>& arr, int low, int high, size_t& comparisons, size_t& swaps)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high, comparisons, swaps);

        quickSort(arr, low, pivotIndex - 1, comparisons, swaps);
        quickSort(arr, pivotIndex + 1, high, comparisons, swaps);
    }
}

void quickSortWithStats(vector<size_t>& arr, size_t& comparisons, size_t& swaps)
{
    comparisons = 0;
    swaps = 0;
    quickSort(arr, 0, arr.size() - 1, comparisons, swaps);
}

void heapify(vector<size_t>& arr, int num, int i, size_t& comparisons, size_t& swaps)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    ++comparisons;
    if (l < num && arr[l] > arr[largest])
    {
        largest = l;
    }
    ++comparisons;
    if (r < num && arr[r] > arr[largest])
    {
        largest = r;
    }
    ++comparisons;
    if (largest != i)
    {
        ++swaps;
        swap(arr[i], arr[largest]);
        heapify(arr, num, largest, comparisons, swaps);
    }
}

void heapSort(vector<size_t>& arr, size_t& comparisons, size_t& swaps)
{
    comparisons = 0;
    swaps = 0;
    
    for (int i = arr.size() / 2 - 1; i >= 0; i--)
        heapify(arr, arr.size(), i, comparisons, swaps);

    for (int i = arr.size() - 1; i > 0; i--)
    {
        ++swaps;
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, comparisons, swaps);
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
    cout << "- Best cases:" << std::endl;
    for (size_t i = 100; i <= 1000000; i *= 10)
    {
        sortingOutput(func, createArr(i, false));
    }
    cout << "- Worst cases:" << std::endl;
    for (size_t i = 100; i <= 1000000; i *= 10)
    {
        sortingOutput(func, createArr(i, true));
    }
}
int main()
{
   
    cout << "Heap sort:" << endl;
    sorting(heapSort);

    cout << "Quick sort:" << endl;
    sorting(quickSortWithStats);

    return 0;

}
