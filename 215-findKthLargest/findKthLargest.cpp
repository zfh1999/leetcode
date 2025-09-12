#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end(), greater<int>());
        for (auto i : nums)
            cout << i << ", ";
        cout << endl;

        sort_heap(nums.begin(), nums.end(), greater<int>());
        for (auto i : nums)
            cout << i << ", ";
        cout << endl;
        return nums[k - 1];
    }
};

int main()
{
    Solution s;
    vector<int> v{3,2,3,1,2,4,5,5,6};
    s.findKthLargest(v, 4);
}