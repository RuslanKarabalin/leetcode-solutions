#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<int> buildArray(std::vector<int>& nums) {
        std::vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            result[i] = nums[nums[i]];
        }
        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::vector<int> nums = {0, 2, 1, 5, 3, 4};
    auto result = s.buildArray(nums);
    for (int i = 0; i < result.size(); ++i) {
        if (i > 0)
            std::cout << ", ";
        std::cout << result[i];
    }
    std::cout << std::endl;

    return 0;
}
