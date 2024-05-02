#include <iostream>

using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapSort(int (&array)[], int n)
{
    for (int i = n - 1; 0 < i; i--)
    {
        for (int j = i; 0 < j; j--)
        {
            if (array[j] > array[(j - 1) / 2])
            {
                swap(array[j], array[(j - 1) / 2]);
            }
        }

        swap(array[i], array[0]);
    }

    // Print values
    printArray(array, n);
    return;
}

int main()
{

    int numbers[] = {7, 3, 2, 5, 6, 10, 9, 8, 1};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    heapSort(numbers, n);

    return 0;
}