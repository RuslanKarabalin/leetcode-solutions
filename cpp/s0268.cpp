#include <iostream>
#include <vector>

class Solution {
   public:
    int missingNumber(std::vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;
        for (int x : nums) {
            actualSum += x;
        }
        return expectedSum - actualSum;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    std::cout << s.missingNumber(nums) << std::endl;

    return 0;
}
