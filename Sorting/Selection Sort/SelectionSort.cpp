#include <iostream>

using namespace std;

void selectionSort(int (&array)[], int n)
{
    int minIndex;
    for (int i = 0; i < n - 2; i++)
    {
        minIndex = i;
        for (int j = i; j < n; j++)
        {
            if (array[j] < array[minIndex])
                minIndex = j;
        }
        if (i != minIndex)
            swap(array[i], array[minIndex]);
    }

    // Print values
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    return;
}

int main()
{

    int numbers[] = {7, 3, 2, 5, 6, 10, 9, 8, 1};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    selectionSort(numbers, n);

    return 0;
}