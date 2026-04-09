#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
        std::sort(nums.begin(), nums.end());
        long long count = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int left = lowerBound(nums, lower - nums[i], i + 1);
            int right = upperBound(nums, upper - nums[i], i + 1);
            count += (right - left);
        }

        return count;
    }

   private:
    int lowerBound(std::vector<int>& nums, int target, int start) {
        int left = start;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    int upperBound(std::vector<int>& nums, int target, int start) {
        int left = start;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::vector<int> nums1 = {0, 1, 7, 4, 4, 5};
    std::cout << s.countFairPairs(nums1, 3, 6) << std::endl;

    std::vector<int> nums2 = {1, 7, 9, 2, 5};
    std::cout << s.countFairPairs(nums2, 11, 11) << std::endl;

    return 0;
}
