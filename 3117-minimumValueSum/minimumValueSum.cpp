#include <climits>
#include <numeric>
#include <vector>

using namespace std;

class Solution
{
  public:
    int minimumValueSum(vector<int> &nums, vector<int> &andValues)
    {
        int n = nums.size();
        int m = andValues.size();
        bool is_first = true;
        int r = 0;
        vector<int> dp(m, INT_MAX);
        for (int i = 0; i < m; ++i)
        {
            for (int j = r; j < n; ++j)
            {
                int bitwise_and_result =
                    std::accumulate(nums.begin() + r, nums.begin() + j + 1, ~0, std::bit_and<int>());
                if (bitwise_and_result == andValues[i])
                {
                    if (is_first)
                    {
                        r = j + 1;
                        is_first = false;
                    }
                    dp[i] = min(dp[i], nums[j]);
                }
            }
            is_first = true;
            if (dp[i] == INT_MAX)
                return -1;
        }
        return std::accumulate(dp.begin(), dp.end(), 0);
    }
};

int main()
{
    Solution s;
    vector<int> n{1, 3, 2, 4, 7, 5, 3};
    vector<int> m{0, 5, 3};
    s.minimumValueSum(n, m);
}