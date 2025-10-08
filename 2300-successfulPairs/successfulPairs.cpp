#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        vector<int> pairs(spells.size(), 0);
        std::sort(potions.begin(), potions.end());
        for (int i = 0; i < spells.size(); ++i)
        {
            auto it = std::lower_bound(potions.begin(), potions.end(), ceil(success / (double)spells[i]));
            pairs[i] = distance(it, potions.end());
        }
        return pairs;
    }
};