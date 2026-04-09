#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            if (nums[start] % 2 != 0 && nums[end] % 2 == 0) {
                std::swap(nums[start], nums[end]);
                start++;
                end--;
            } else if (nums[start] % 2 == 0 && nums[end] % 2 == 0) {
                start++;
            } else {
                end--;
            }
        }

        return nums;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::vector<int> nums = {3, 1, 2, 4};
    auto result = s.sortArrayByParity(nums);
    for (int i = 0; i < result.size(); ++i) {
        if (i > 0)
            std::cout << ", ";
        std::cout << result[i];
    }
    std::cout << std::endl;

    return 0;
}
