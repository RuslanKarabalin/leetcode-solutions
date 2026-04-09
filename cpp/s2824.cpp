#include <iostream>
#include <vector>

class Solution {
   public:
    int countPairs(std::vector<int>& nums, int target) {
        int count = 0;
        for (int i = 0; i < (int)nums.size() - 1; ++i) {
            for (int j = i + 1; j < (int)nums.size(); ++j) {
                if (nums[i] + nums[j] < target) {
                    ++count;
                }
            }
        }
        return count;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::vector<int> nums = {-6, 2, 5, -2, -7, -1, 3};
    std::cout << s.countPairs(nums, -2) << std::endl;

    return 0;
}
