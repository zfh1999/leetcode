/*给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组
[0,3,1,6,2,2,7] 的 子序列 。*/

// f(n) = f(n-1) + 1 or
// f(n) = f(n-1)
// f(1) = 1

// 4 10 4 3 8 9

#include <algorithm>
#include <vector>

class Solution
{
  public:
    int lengthOfLIS(std::vector<int> &nums)
    {
        std::vector<int> dp(nums.size());
        if (nums.size() == 0)
        {
            return 0;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            dp[i] = 1;
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};