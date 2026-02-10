#include <iostream>
#include <vector>

class Solution {
   public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        int k = 0;
        int s = m + n;
        std::vector<int> arr(s);

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                arr[k++] = nums1[i++];
            } else {
                arr[k++] = nums2[j++];
            }
        }

        while (i < m) {
            arr[k++] = nums1[i++];
        }

        while (j < n) {
            arr[k++] = nums2[j++];
        }

        for (int l = 0; l < s; ++l) {
            nums1[l] = arr[l];
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};
    s.merge(nums1, 3, nums2, 3);

    for (int n : nums1) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
