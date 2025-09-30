#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int triangularSum(vector<int> &nums)
    {
        vector<int> newNums;
        while (nums.size() > 1)
        {
            newNums.clear();
            for (auto i = 0; i < nums.size() - 1; ++i)
            {
                newNums.push_back((nums[i] + nums[i + 1]) % 10);
            }
            nums = newNums;
        }

        return nums.front();
    }
};