#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    int findMaxLength(std::vector<int>& nums) {
        std::unordered_map<int, int> map;
        int maxLength = 0;
        int prefixSum = 0;

        map[0] = -1;

        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += (nums[i] == 0) ? -1 : 1;

            if (map.count(prefixSum)) {
                maxLength = std::max(maxLength, i - map[prefixSum]);
            } else {
                map[prefixSum] = i;
            }
        }

        return maxLength;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::vector<int> nums = {0, 0, 1, 0, 0, 1, 1};
    std::cout << s.findMaxLength(nums) << std::endl;

    return 0;
}
