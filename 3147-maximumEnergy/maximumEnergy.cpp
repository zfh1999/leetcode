#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
  public:
    int maximumEnergy(vector<int> &energy, int k)
    {
        int n = energy.size();
        vector<int> dp(n, 0);

        for (int i = 0; i < energy.size(); ++i)
        {
            if (i - k < 0)
            {
                dp[i] = energy[i];
            }
            else
            {
                dp[i] = max(0, dp[i-k])+energy[i];
            }
        }
        return *max_element(dp.begin()+n-k, dp.end());
    }
};

int main()
{
    Solution s;
    vector<int> energy{5,2,-10,-5,1};
    s.maximumEnergy(energy, 3);
}