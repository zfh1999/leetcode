#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

class Solution
{
public:
	int longestValidParentheses(const std::string &s)
	{
		int maxsize = 0;
		std::stack<int> stk;
		stk.push(-1);
		for(int i = 0; i < s.size(); ++i)
		{
			if(s[i]=='(')
			{
				stk.push(i);
			}
			else{
				stk.pop();
				if(stk.empty())
				{
					stk.push(i);
				}
				else
				{
					maxsize = std::max(maxsize, i - stk.top());
				}
			}
		}

		return maxsize;
	}
};

int main()
{
	Solution s;
	std::cout << s.longestValidParentheses("()(())");
}