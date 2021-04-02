#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

void dfs(vector<vector<char>> &grid, int i, int j, int n, int m)
{
    grid[i][j] = '0';
    if (i - 1 >= 0 && grid[i - 1][j] == '1')
        dfs(grid, i - 1, j, n, m);
    if (j - 1 >= 0 && grid[i][j - 1] == '1')
        dfs(grid, i, j - 1, n, m);
    if (i + 1 < n && grid[i + 1][j] == '1')
        dfs(grid, i + 1, j, n, m);
    if (j + 1 < m && grid[i][j + 1] == '1')
        dfs(grid, i, j + 1, n, m);
}

int numIslands(vector<vector<char>> &grid)
{
    // write code here
    int n = grid.size();
    if (n == 0)
    {
        return 0;
    }
    int m = grid[0].size();
    int num = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == '1')
            {
                ++num;
                dfs(grid, i, j, n, m);
            }
        }
    }
    return num;
}

int main()
{
    string str1 = "1";
    string str2 = "99";
    vector<vector<char>> vec = {{1, 1, 0, 0, 0}, {0, 1, 0, 1, 1}, {0, 0, 0, 1, 1}, {0, 0, 0, 0, 0}, {0, 0, 1, 1, 1}};
    cout << solve(vec) << endl;

    return 0;
}