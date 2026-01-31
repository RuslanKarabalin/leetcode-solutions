#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
    out << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        const auto& x = v[i];
        out << x;
        if (i < v.size() - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

class Solution {
   public:
    double findMedianSortedArrays(std::vector<int>& nums1,
                                  std::vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int k = 0;
        int s = nums1.size() + nums2.size();
        std::vector<int> merged(s);
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                merged[k++] = nums1[i++];
            } else {
                merged[k++] = nums2[j++];
            }
        }
        while (i < nums1.size()) {
            merged[k++] = nums1[i++];
        }
        while (j < nums2.size()) {
            merged[k++] = nums2[j++];
        }
        if (s % 2 == 0) {
            return (merged[(s / 2) - 1] + merged[(s / 2)]) / 2.0;
        } else {
            return (double)merged[(s / 2)];
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::vector<int> nums01 = {1, 2};
    std::vector<int> nums02 = {3, 4};

    std::cout << s.findMedianSortedArrays(nums01, nums02) << std::endl;

    return 0;
}
