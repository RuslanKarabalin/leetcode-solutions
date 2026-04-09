#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<int> getConcatenation(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result(n * 2);
        for (int i = 0; i < n; ++i) {
            result[i] = nums[i];
            result[i + n] = nums[i];
        }
        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::vector<int> nums = {1, 2, 1};
    auto result = s.getConcatenation(nums);
    for (int i = 0; i < result.size(); ++i) {
        if (i > 0)
            std::cout << ", ";
        std::cout << result[i];
    }
    std::cout << std::endl;

    return 0;
}
