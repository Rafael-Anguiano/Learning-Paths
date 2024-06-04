#include <iostream>
#include <vector>

using namespace std;

vector<int> countingSort(vector<int> &nums)
{
    for (unsigned int i = 0; i < nums.size(); i++)
    {
        nums[i] = i;
    }
    return nums;
}

int main()
{
    vector<int> numbers = {5, 1, 6, 4, 3, 2, 0};

    for (unsigned int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    numbers = countingSort(numbers);

    for (unsigned int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
