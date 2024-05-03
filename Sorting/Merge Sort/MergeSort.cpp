#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> arrayA, vector<int> arrayB)
{
    vector<int> arrayC;

    while (arrayA.size() != 0 && arrayB.size() != 0)
    {
        if (arrayA[0] < arrayB[0])
        {
            arrayC.push_back(arrayA[0]);
            arrayA.erase(arrayA.begin());
        }
        else
        {
            arrayC.push_back(arrayB[0]);
            arrayB.erase(arrayB.begin());
        }
    }

    while (arrayA.size() != 0)
    {
        arrayC.push_back(arrayA[0]);
        arrayA.erase(arrayA.begin());
    }
    while (arrayB.size() != 0)
    {
        arrayC.push_back(arrayB[0]);
        arrayB.erase(arrayB.begin());
    }

    return arrayC;
}

vector<int> mergeSort(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums;

    vector<int> arrayA;
    vector<int> arrayB;

    for (unsigned int i = 0; i < nums.size(); i++)
    {
        if (i < nums.size() / 2)
            arrayA.push_back(nums[i]);
        if (i >= nums.size() / 2)
            arrayB.push_back(nums[i]);
    }

    arrayA = mergeSort(arrayA);
    arrayB = mergeSort(arrayB);

    return merge(arrayA, arrayB);
}

int main()
{
    vector<int> numbers = {7, 3, 2, 5, 6, 10, 9, 8, 1};

    for (unsigned int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    numbers = mergeSort(numbers);

    for (unsigned int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
