#include <iostream>

using namespace std;

void bubbleSort(int (&array)[], int n)
{
    bool hasSwaped;
    for (int i = 0; i < n; i++)
    {
        hasSwaped = false;
        for (int j = 0; j < n - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                hasSwaped = true;
            }
        }
        if (!hasSwaped)
            break;
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

    bubbleSort(numbers, n);

    return 0;
}