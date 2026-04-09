#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    std::vector<int> intersect(std::vector<int>& nums1,
                               std::vector<int>& nums2) {
        std::unordered_map<int, int> map1;
        std::unordered_map<int, int> map2;

        for (int num : nums1) {
            map1[num]++;
        }

        for (int num : nums2) {
            map2[num]++;
        }

        std::vector<int> result;
        for (auto& [num, count1] : map1) {
            int count2 = map2.count(num) ? map2[num] : 0;
            int minCount = std::min(count1, count2);
            for (int i = 0; i < minCount; ++i) {
                result.push_back(num);
            }
        }

        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::vector<int> nums1 = {4, 9, 5};
    std::vector<int> nums2 = {9, 4, 9, 8, 4};
    auto result = s.intersect(nums1, nums2);
    for (int i = 0; i < result.size(); ++i) {
        if (i > 0)
            std::cout << ", ";
        std::cout << result[i];
    }
    std::cout << std::endl;

    return 0;
}
