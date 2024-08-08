/*给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。
例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。*/

// 可以组成n的平方数必然在1~~根号n中间
// f(n)=1+{f(n-k*k)|min|1<=k<=根号n}

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

class Solution
{
  public:
    int numSquares(int n)
    {
        std::vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            dp[i] = 5;
            int sqrt = std::sqrt(i);
            for (int j = 1; j <= sqrt; ++j)
            {
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    std::cout << s.numSquares(12) << std::endl;
}