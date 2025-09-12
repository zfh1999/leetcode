/*
在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。
你从其中的一个加油站出发，开始时油箱为空。

给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，
则返回出发时加油站的编号，否则返回 -1 。如果存在解，则 保证 它是 唯一 的。
*/

#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

// 找到一个i值，使得gas[i]-cost[i]+gas[i+1]-cost[i+1]+...+gas[i-1]-cost[i-1] 始终不为负数

class Solution
{
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int temp = 0;
        int ans = -1;
        int sum = 0;
        for (int i = 0; i < gas.size(); ++i)
        {
            temp += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (sum < 0)
            {
                ans = i;
                sum = 0;
            }
        }
        if (temp < 0)
            return -1;
        else
            return ans + 1;
        
    }
};

int main(int argc, char *argv[])
{
    vector<int> gas{2,3,4};
    vector<int> cost{3,4,3};
    Solution s;
    cout << s.canCompleteCircuit(gas, cost) << endl;
}