#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    int minimumCost(std::vector<int>& nums) {
        int s = nums[0];
        std::sort(nums.begin() + 1, nums.end());
        return s + nums[1] + nums[2];
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::vector<int> a1 = {1, 2, 3, 12};
    std::cout << s.minimumCost(a1) << std::endl;

    std::vector<int> a2 = {10, 3, 1, 1};
    std::cout << s.minimumCost(a2) << std::endl;

    return 0;
}
