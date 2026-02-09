#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::vector<int>> result;

        for (int i = 0; i < (1 << n); ++i) {
            std::vector<int> subset;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    subset.push_back(nums[j]);
                }
            }
            result.push_back(subset);
        }

        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> res = s.subsets(nums);

    for (const auto& subset : res) {
        std::cout << "[";
        for (size_t i = 0; i < subset.size(); ++i) {
            if (i > 0) {
                std::cout << ", ";
            }
            std::cout << subset[i];
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
