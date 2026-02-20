#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
   public:
    std::vector<int> intersection(std::vector<int>& nums1,
                                  std::vector<int>& nums2) {
        std::unordered_set<int> set1(nums1.begin(), nums1.end());
        std::vector<int> result;
        std::unordered_set<int> seen;
        for (int num : nums2) {
            if (set1.count(num) && !seen.count(num)) {
                result.push_back(num);
                seen.insert(num);
            }
        }
        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::vector<int> nums1 = {1, 2, 2, 1};
    std::vector<int> nums2 = {2, 2};
    auto result = s.intersection(nums1, nums2);
    for (int i = 0; i < result.size(); ++i) {
        if (i > 0)
            std::cout << ", ";
        std::cout << result[i];
    }
    std::cout << std::endl;

    return 0;
}
