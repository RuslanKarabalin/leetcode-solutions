#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }

        int maxLen = -1;
        sort(nums.begin(), nums.end());

        int same = 0;
        int l = 0;
        int r = 1;
        while (r < n) {
            if (nums[r - 1] == nums[r]) {
                ++r;
                ++same;
            } else if (nums[r - 1] + 1 == nums[r]) {
                ++r;
            } else {
                int s = r - l - same;
                if (s > maxLen) {
                    maxLen = s;
                }
                l = r;
                same = 0;
                ++r;
            }
        }
        int s = r - l - same;
        if (s > maxLen) {
            maxLen = s;
        }
        return maxLen;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    vector<int> in = {0, 0};
    cout << s.longestConsecutive(in) << std::endl;

    return 0;
}
