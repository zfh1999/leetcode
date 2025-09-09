/*
在第 1 天，有一个人发现了一个秘密。

给你一个整数 delay ，表示每个人会在发现秘密后的 delay 天之后，每天 给一个新的人 分享 秘密。同时给你一个整数 forget ，
表示每个人在发现秘密 forget 天之后会 忘记 这个秘密。一个人 不能 在忘记秘密那一天及之后的日子里分享秘密。

给你一个整数 n ，请你返回在第 n 天结束时，知道秘密的人数。由于答案可能会很大，请你将结果对 10^9 + 7 取余 后返回。
*/
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution
{
  public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        // 使用一个数组来记录每一天新知道秘密的人数
        vector<long long> newPeople(n + 1, 0);
        newPeople[1] = 1; // 第1天有1个人知道秘密

        long long totalKnown = 1; // 总人数
        long long shareable = 0;  // 今天可以分享秘密的人数

        long long MOD = 1e9 + 7;

        for (int i = 2; i <= n; ++i)
        {
            // 在i-1天，新增加可以分享秘密的人 (i-1-delay天知道秘密的人)
            if (i - delay >= 1)
            {
                shareable = (shareable + newPeople[i - delay]) % MOD;
            }

            // 在i-1天，忘记秘密的人 (i-1-forget天知道秘密的人)
            if (i - forget >= 1)
            {
                shareable = (shareable - newPeople[i - forget] + MOD) % MOD;
            }

            // 今天新知道秘密的人 = 昨天可以分享秘密的人
            newPeople[i] = shareable;
            totalKnown = (totalKnown + newPeople[i] + MOD) % MOD;

            // 检查今天是否有人忘记秘密
            if (i - forget >= 1)
            {
                totalKnown = (totalKnown - newPeople[i - forget] + MOD) % MOD;
            }
        }
        return totalKnown;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int n, d, f = 0;
    n = atoi(argv[1]);
    d = atoi(argv[2]);
    f = atoi(argv[3]);
    printf("%d\n", s.peopleAwareOfSecret(n, d, f));
    return 0;
}