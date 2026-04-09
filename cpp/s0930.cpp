#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    int numSubarraysWithSum(std::vector<int>& nums, int goal) {
        int result = 0;
        int sum = 0;
        std::unordered_map<int, int> freq;

        for (int n : nums) {
            sum += n;

            if (sum == goal) {
                result++;
            }

            if (freq.count(sum - goal)) {
                result += freq[sum - goal];
            }
            freq[sum]++;
        }

        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::vector<int> nums = {1, 0, 1, 0, 1};
    std::cout << s.numSubarraysWithSum(nums, 2) << std::endl;

    return 0;
}
