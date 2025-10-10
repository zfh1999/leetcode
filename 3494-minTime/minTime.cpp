#include <iostream>
#include <vector>

using namespace std;

// class Solution
// {
//   public:
//     long long minTime(vector<int> &skill, vector<int> &mana)
//     {
//         vector<long long> last_pre(skill.size(), 0);
//         vector<long long> pre(skill.size(), 0);

//         for (int j = 0; j < skill.size(); ++j)
//         {
//             last_pre[j] = skill[j] * mana[0] + (j > 0 ? last_pre[j - 1] : 0);
//         }

//         // {
//         //     cout << "loop 0 : ";
//         //     for (const auto &x : last_pre)
//         //     {
//         //         cout << x << ", ";
//         //     }
//         //     cout << endl;
//         // }

//         for (int i = 1; i < mana.size(); ++i)
//         {
//             for (long long k = last_pre.front(); k <= last_pre.back(); ++k)
//             {
//                 for (int j = 0; j < skill.size(); ++j)
//                 {
//                     pre[j] = skill[j] * mana[i] + (j > 0 ? pre[j - 1] : k);
//                     if (j == skill.size() - 1)
//                         break;
//                     if (pre[j] < last_pre[j + 1])
//                         break;
//                 }
//                 if (pre.back() >= last_pre.back())
//                     break;
//             }
//             last_pre.swap(pre);
//             pre = vector<long long>(skill.size(), 0);

//             // {
//             //     cout << "loop " << i << " : ";
//             //     for (const auto &x : last_pre)
//             //     {
//             //         cout << x << ", ";
//             //     }
//             //     cout << endl;
//             // }
//         }

//         return last_pre.back();
//     }
// };

class Solution
{
  public:
    long long minTime(vector<int> &skill, vector<int> &mana)
    {
        vector<vector<long long>> dp(mana.size(), vector<long long>(skill.size(), 0));

        dp[0][0] = skill[0] * mana[0];
        for (int j = 1; j < skill.size(); ++j)
        {
            dp[0][j] = dp[0][j - 1] + skill[j] * mana[0];
        }

        for (int i = 1; i < mana.size(); ++i)
        {
            dp[i][0] = dp[i - 1][0] + skill[0] * mana[i];
            for (int j = 1; j < skill.size(); ++j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + skill[j] * mana[i];
            }

            for (int j = skill.size() - 2; j >= 0; --j)
            {
                dp[i][j] = dp[i][j+1]-skill[j+1]*mana[i];
            }
        }

        return dp[mana.size() - 1][skill.size() - 1];
    }
};

int main()
{
    Solution s;
    vector<int> skill{3, 1};
    vector<int> mana{10, 1};
    cout << s.minTime(skill, mana) << endl;
}