#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        int l = 0;
        int r = 0;
        int maxLen = 0;
        while (r < n) {
            if (nums[r] == 1) {
                ++r;
            } else {
                maxLen = max(r - l, maxLen);
                while (nums[r] == 0) {
                    if (r + 1 < n) {
                        ++r;
                    } else {
                        return maxLen;
                    }
                }
                l = r;
            }
        }
        maxLen = max(r - l, maxLen);
        return maxLen;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;

    vector<int> in = {1, 1, 0, 1, 1, 1};
    cout << s.findMaxConsecutiveOnes(in) << "\n";

    return 0;
}
