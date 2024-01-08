#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    std::string convert(const std::string &s, int numRows)
    {
        std::vector<std::string> matrix;
        int t = 2 * (numRows - 1);
        int count = numRows / t;
        int remainder = numRows % t;
        if (remainder != 0)
            count += 1;
        for (int i = 0; i < count; ++i)
        {
            for (int j = 0; j < numRows; ++j)
            {
                if(i * t + j > s.size()) break;
                matrix[j].push_back(s[i * t + j]);
            }
            for (int j = 0; j < numRows - 2; ++j)
            {
                if(i * t + numRows) break;
                matrix[numRows - 1 - j - 1].push_back(s[i * t + numRows]);
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
    std::cout << s.convert("PAYPALISHIRING", 3) << std::endl;
}