#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    std::string convert(const std::string &s, int numRows)
    {
        if(numRows == 1)
        {
            return s;
        }
        std::vector<std::string> matrix(numRows);
        int t = 2 * (numRows - 1);
        bool flag;
        int count = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(count == numRows - 1)
            {
                flag = false;
            }
            if(count == 0)
            {
                flag = true;
            }

            matrix[count] += s[i];

            if(flag)
            {
                ++count;
            }
            else
            {
                --count;
            }
        }
        return [](std::vector<std::string> &s2) -> std::string
        {
            std::string ss;
            for (auto &sss : s2)
            {
                ss.append(sss);
            }
            return ss;
        }(matrix);
    }
};

int main()
{
    Solution s;
    std::cout << s.convert("PAYPALISHIRING", 4) << std::endl;
}