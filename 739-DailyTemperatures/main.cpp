/*
 * 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，
 * 其中 answer[i] 是指对于第 i 天，
 * 下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
        std::stack<int> stk;
        std::vector<int> result(temperatures.size());
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
                auto index = stk.top();
                result[index] = i - index;
                stk.pop();
            }
            stk.push(i);
        }
        return result;
    }
};

int main() {
    std::vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};
    Solution so;
    auto res = so.dailyTemperatures(temperatures);
    std::for_each(res.begin(), res.end(),
                  [](int& i){std::cout << i << '\n';});
    return 0;
}
