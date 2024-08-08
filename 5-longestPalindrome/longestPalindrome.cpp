#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <memory>

class Solution
{
public:
    std::string longestPalindrome(const std::string &s)
    {
        std::pair<int, int> max_pair;
        int max_length = 1;
        if (s.size() < 2)
        {
            return s;
        }
        if (s.size() == 2 && s[0] == s[1])
        {
            return s;
        }

        for (int i = 0; i < s.size() - 1; i++)
        {
            for (int j = i + max_length; j < s.size(); j++)
            {
                if(j > s.length())
                {
                    break;
                }
                if (isPalindrome(s, i, j))
                {          
                    max_length = j - i + 1;
                    max_pair = std::make_pair(i, j);
                }
            }
        }
        return s.substr(max_pair.first, max_pair.second - max_pair.first + 1);
    }

    bool isPalindrome(const std::string &s, int begin, int end)
    {
        while (begin < end)
        {
            if (s[begin] != s[end])
            {
                return false;
            }
            begin++;
            end--;
        }
        return true;
    }
};

int main()
{
    Solution s;
    auto str{"jrjnbctoqgzimtoklkxcknwmhiztomaofwwzjnhrijwkgmwwuazcowskjhitejnvtblqyepxispasrgvgzqlvrmvhxusiqqzzibcyhpnruhrgbzsmlsuacwptmzxuewnjzmwxbdzqyvsjzxiecsnkdibudtvthzlizralpaowsbakzconeuwwpsqynaxqmgngzpovauxsqgypinywwtmekzhhlzaeatbzryreuttgwfqmmpeywtvpssznkwhzuqewuqtfuflttjcxrhwexvtxjihunpywerkktbvlsyomkxuwrqqmbmzjbfytdddnkasmdyukawrzrnhdmaefzltddipcrhuchvdcoegamlfifzistnplqabtazunlelslicrkuuhosoyduhootlwsbtxautewkvnvlbtixkmxhngidxecehslqjpcdrtlqswmyghmwlttjecvbueswsixoxmymcepbmuwtzanmvujmalyghzkvtoxynyusbpzpolaplsgrunpfgdbbtvtkahqmmlbxzcfznvhxsiytlsxmmtqiudyjlnbkzvtbqdsknsrknsykqzucevgmmcoanilsyyklpbxqosoquolvytefhvozwtwcrmbnyijbammlzrgalrymyfpysbqpjwzirsfknnyseiujadovngogvptphuyzkrwgjqwdhtvgxnmxuheofplizpxijfytfabx"};
    auto ss = s.longestPalindrome(str);
    std::cout << ss << std::endl;
}