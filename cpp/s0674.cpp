#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    int findLengthOfLCIS(std::vector<int>& nums) {
        if (nums.empty())
            return 0;

        int result = 0;
        int l = 0;
        int r = 1;
        int len = 0;

        while (r < nums.size()) {
            if (nums[r - 1] < nums[r]) {
                r++;
                len++;
            } else {
                l++;
                r = l + 1;
                result = std::max(result, len + 1);
                len = 0;
            }
        }

        result = std::max(result, len + 1);
        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::vector<int> nums1 = {1, 3, 5, 4, 7};
    std::cout << s.findLengthOfLCIS(nums1) << std::endl;

    std::vector<int> nums2 = {2, 2, 2, 2, 2};
    std::cout << s.findLengthOfLCIS(nums2) << std::endl;

    return 0;
}
