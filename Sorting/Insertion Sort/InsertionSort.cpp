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

void insertionSort(int (&array)[], int n)
{
    int currentIndex;
    for (int i = 1; i < n; i++)
    {
        currentIndex = i;

        while (currentIndex > 0 && array[currentIndex - 1] > array[currentIndex])
        {
            swap(array[currentIndex], array[currentIndex - 1]);
            currentIndex--;
        }
    }

    // Print values
    printArray(array, n);
    return;
}

int main()
{

    int numbers[] = {7, 3, 2, 5, 6, 10, 9, 8, 1};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    insertionSort(numbers, n);

    return 0;
}