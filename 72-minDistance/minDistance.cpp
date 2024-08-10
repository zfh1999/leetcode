#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    int minDistance(string word1, string word2)
    {
        int l1 = word1.length();
        int l2 = word2.length();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));
        for (int n = 0; n <= l2; ++n)
            dp[0][n] = n;
        for (int n = 0; n <= l1; ++n)
            dp[n][0] = n;

        for (int i = 1; i <= l1; ++i)
        {
            for (int j = 1; j <= l2; ++j)
            {
                if (word1.at(i - 1) == word2.at(j - 1))
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
            }
        }
        return dp[l1][l2];
    }
};

int main()
{
    Solution s;
    printf("%d\n", s.minDistance("horse", "ros"));
}
