#include <iostream>
#include <vector>

class Solution {
   public:
    int searchInsert(std::vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 && target <= nums[i]) {
                return i;
            }
            if (i == nums.size() - 1) {
                return nums.size();
            }
            if (nums[i] < target && target <= nums[i + 1]) {
                return i + 1;
            }
        }
        return nums.size();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::vector<int> nums1 = {1, 3, 5, 6};
    std::cout << s.searchInsert(nums1, 5) << std::endl;
    std::vector<int> nums2 = {1, 3, 5, 6};
    std::cout << s.searchInsert(nums2, 7) << std::endl;
    std::vector<int> nums3 = {1, 3, 5, 6};
    std::cout << s.searchInsert(nums3, 0) << std::endl;

    return 0;
}
