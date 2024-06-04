#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int nQueries;
    cin >> nQueries;

    vector<vector<int>> queries;
    for (int i = 0; i < nQueries; i++)
    {
        vector<int> temp;
        for (int j = 0; j < 2; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        queries.push_back(temp);
    }
    for (int q = 0; q < nQueries; q++)
    {
        int min = INT_MAX;
        for (int i = queries[q][0] - 1; i < queries[q][1]; i++)
        {
            for (int j = queries[q][0] - 1; j < queries[q][1]; j++)
            {
                if (i == j)
                    continue;
                if (nums[i] == nums[j])
                {
                    min = 0;
                    break;
                }
                if (abs(nums[i] - nums[j]) < min)
                {
                    min = abs(nums[i] - nums[j]);
                }
            }
            if (min == 0)
                break;
        }
        cout << min << endl;
    }
    return 0;
}