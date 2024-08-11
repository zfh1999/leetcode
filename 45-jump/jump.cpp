#include <vector>

using namespace std;

class Solution
{
  public:
    int jump(vector<int> &nums)
    {
        int end = 0;
        int count = 0;
        int change = 0;
        // 不遍历最后一个元素，因为n-1个元素必然需要到达最后的元素
        // 遍历最后元素会导致当前面正好到底最后元素时count多增加1
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            end = max(end, i + nums[i]);
            if (i == change)
            {

                change = end;
                count++;
            }
        }
        return count;
    }
};