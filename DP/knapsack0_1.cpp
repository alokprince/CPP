#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> wt, vector<int> val, int n, int w)
{
    vector<vector<int>> t(n + 1, vector<int>(w + 1));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {

            if (i == 0)
            {
                t[i][j] = 0;
            }
            if( j == 0){
                t[i][j] = 0;
            }
        }
    }
  
    // cout << t.size();
    // if( n == 0 || w == 0){
    //     return 0;
    // }
    // if(t[n][w] != -1){
    //     return t[n][w];
    // }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            // n -> i   w -> j
            if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[ i - 1][ j - wt[i - 1]],t[i - 1][ j]);
            }
            else if (wt[i - 1] > j)
            {
               t[i][j] = t[i - 1][ j];
            }
        }
    }
    return t[n][w];
}

int main()
{
    vector<int> wt = {10, 20, 30};
    vector<int> val = {60, 100, 120};
    int w = 50;
    cout << knapsack(wt, val, wt.size(), w);
}
//  { 60, 100, 120 };
//  { 10, 20, 30 };
//   50;