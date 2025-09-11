#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> table{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<int> index;
        vector<char> vowels;

        for (int i = 0; i < s.length(); ++i)
        {
            if (table.find(s[i]) != table.end())
            {
                index.push_back(i);
                vowels.push_back(s[i]);
            }
        }

        sort(vowels.begin(), vowels.end());

        for (int i = 0; i < index.size(); ++i)
        {
            s[index[i]] = vowels[i];
        }

        return s;
    }
};

int main(int argc, char* argv[])
{
    string s = argv[1];
    Solution so;
    cout << so.sortVowels(s) << endl;
}