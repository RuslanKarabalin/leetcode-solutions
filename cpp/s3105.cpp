#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    int longestMonotonicSubarray(std::vector<int>& nums) {
        if (nums.empty())
            return 0;
        int maxLen = 1;
        int inc = 1;
        int dec = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                inc++;
                dec = 1;
            } else if (nums[i] < nums[i - 1]) {
                dec++;
                inc = 1;
            } else {
                inc = 1;
                dec = 1;
            }
            maxLen = std::max(maxLen, std::max(inc, dec));
        }
        return maxLen;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::vector<int> a1 = {1, 4, 3, 3, 2};
    std::cout << s.longestMonotonicSubarray(a1) << std::endl;

    std::vector<int> a2 = {3, 3, 3, 3};
    std::cout << s.longestMonotonicSubarray(a2) << std::endl;

    std::vector<int> a3 = {3, 2, 1};
    std::cout << s.longestMonotonicSubarray(a3) << std::endl;

    return 0;
}
