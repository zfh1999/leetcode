// f(m,n)==1 | if(m==1 or n==1)
// f(m,n)=f(m-1,n)+f(m,n-1)

#include <iostream>
#include <vector>

class Solution
{
  public:
    int uniquePaths(int m, int n)
    {
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (i == 1 || j == 1)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution s;
    std::cout << s.uniquePaths(3, 7) << std::endl;
}