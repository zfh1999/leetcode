#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        return ranges::any_of(s, [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        });
    }
};


#include <iostream>
int main(int argc, char* argv[])
{
    Solution s;

    cout << s.doesAliceWin(argv[1]) << endl;
}