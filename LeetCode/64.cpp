#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid.at(0).size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                {
                    continue;
                }
                else if (i == 0)
                {
                    grid[i][j] += grid[i][j - 1];
                }
                else if (j == 0)
                {
                    grid[i][j] += grid[i - 1][j];
                }
                else
                {
                    //原 grid 矩阵元素中被覆盖为 dp 元素后（都处于当前遍历点的左上方），不会再被使用到。
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
                }
            }
        }
        return grid[n - 1][m - 1];
    }
};

int main(int argc, char **argv)
{
    Solution s = Solution();

    vector<vector<int>> obstacleGrid;
    for (int i = 0; i < 3; ++i)
        obstacleGrid.push_back(vector<int>());

    obstacleGrid[0].push_back(1);
    obstacleGrid[0].push_back(3);
    obstacleGrid[0].push_back(1);

    obstacleGrid[1].push_back(1);
    obstacleGrid[1].push_back(5);
    obstacleGrid[1].push_back(1);

    obstacleGrid[2].push_back(4);
    obstacleGrid[2].push_back(2);
    obstacleGrid[2].push_back(1);
    cout << s.minPathSum(obstacleGrid) << endl;
    return 0;
}
