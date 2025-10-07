#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        vector<int> ans(rains.size(), 1);
        vector<int> zeros;
        unordered_map<int, int> lastRainfullDate;

        for (int i = 0; i < rains.size(); ++i)
        {
            if (rains[i])
            {
                ans[i] = -1;
                if (lastRainfullDate.contains(rains[i]))
                {
                    auto it = std::upper_bound(zeros.begin(), zeros.end(), lastRainfullDate[rains[i]]);

                    if (it == zeros.end())
                        return {};
                    
                    ans[*it] = rains[i];
                    zeros.erase(it);
                }

                lastRainfullDate[rains[i]] = i;
            }
            else
            {
                zeros.push_back(i);
            }
        }

        return ans;
    }
};

// 使用set
class Solution
{
  public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        vector<int> ans(rains.size(), 1);
        set<int> zeroDates;
        unordered_map<int, int> lastRainfullDate;

        for (int i = 0; i < rains.size(); ++i)
        {
            if (rains[i])
            {
                ans[i] = -1;
                if (lastRainfullDate.contains(rains[i]))
                {
                    auto it = zeroDates.upper_bound(lastRainfullDate[rains[i]]);
                    if (it == zeroDates.end())
                        return {};
                    ans[*it] = rains[i];
                    zeroDates.erase(it);
                }
                lastRainfullDate[rains[i]] = i;
            }
            else
            {
                zeroDates.emplace(i);
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> rains{1, 2, 0, 0, 2, 1};

    Solution s;
    auto a = s.avoidFlood(rains);
    for (auto i : a)
    {
        cout << i << ", ";
    }
    cout << "\n";
}