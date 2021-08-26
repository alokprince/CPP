#include <bits/stdc++.h>
using namespace std;
bool subset_sum(vector<int> arr, int n, int w)
{

    vector <vector<int>> t(n + 1,vector<int>(w + 1));

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            if (i == 0)
            {
                t[i][j] == false;
            }
            if (j == 0)
            {
                t[i][j] = true;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {

            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            }
            else if (arr[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][w];
}

bool Equal_partition_sum(vector<int> arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    if (sum % 2 != 0)
    {
        return false;
    }
    else
    {
        return subset_sum(arr, n, sum / 2);
    }
}

int main()
{
    vector<int> arr = {1,5,1,2,2,1};
    int n = arr.size();

    cout << Equal_partition_sum(arr, n);
}