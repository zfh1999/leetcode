#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if(s.size() < 2)
        {
            return s;
        }
        if(s.size() == 2 && s[0] == s[1])
        {
            return s;
        }
        else
        {
            return "";
        }
        
        
    }
};