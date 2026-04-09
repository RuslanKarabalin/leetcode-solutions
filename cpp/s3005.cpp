#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    int maxFrequencyElements(std::vector<int>& nums) {
        std::unordered_map<int, int> map;
        int maxFreq = 0;
        for (int x : nums) {
            map[x]++;
            maxFreq = std::max(maxFreq, map[x]);
        }
        int result = 0;
        for (auto& [k, v] : map) {
            if (v == maxFreq) {
                result += maxFreq;
            }
        }
        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::vector<int> nums = {1, 2, 2, 3, 1, 4};
    std::cout << s.maxFrequencyElements(nums) << std::endl;

    return 0;
}
