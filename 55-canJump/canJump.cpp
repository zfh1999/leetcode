#include <vector>

using namespace std;

class Solution
{
  public:
    bool canJump(vector<int> &nums)
    {
        int end = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            end = max(end, i + nums[i]);
            if (end >= nums.size() - 1)
            {
                return true;
            }
            if (end <= i)
            {
                break;
            }
        }
        return false;
    }
};