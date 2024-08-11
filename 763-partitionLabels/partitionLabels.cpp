#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> partitionLabels(string s)
    {
        int last[26] = {0};
        for (int i = 0; i < s.length(); ++i)
        {
            last[s[i] - 'a'] = i;
        }

        vector<int> pos;

        int start = 0, end = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            end = max(end, last[s[i] - 'a']);
            if (end == i)
            {
                pos.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return pos;
    }
};