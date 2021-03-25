#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        //obstacleGrid[0].size()是列
        int n = obstacleGrid.size(), m = obstacleGrid.at(0).size();
        vector<int> f(m);
        f[0] = (obstacleGrid[0][0] == 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; ++j)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    f[j] = 0;
                    continue;
                }
                //obstacleGrid[i][j - 1] == 0可以去掉的原因：
                //如果[i][j - 1] = 0那么加上也没用
                //如果[i][j - 1] ！= 0那么在上一个if中，f[j-1]已经被设置为0
                //不加也罢
                if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0)
                {
                    f[j] += f[j - 1];
                }
            }
        }
        return f.back();
    }
};

int main(int argc, char **argv)
{
    Solution s = Solution();

    vector<vector<int>> obstacleGrid;
    for (int i = 0; i < 3; ++i)
        obstacleGrid.push_back(vector<int>());

    obstacleGrid[0].push_back(0);
    obstacleGrid[0].push_back(0);
    obstacleGrid[0].push_back(0);

    obstacleGrid[1].push_back(0);
    obstacleGrid[1].push_back(1);
    obstacleGrid[1].push_back(0);

    obstacleGrid[2].push_back(0);
    obstacleGrid[2].push_back(0);
    obstacleGrid[2].push_back(0);

    // obstacleGrid[3].push_back(0);
    // obstacleGrid[3].push_back(0);
    // obstacleGrid[3].push_back(0);

    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}
