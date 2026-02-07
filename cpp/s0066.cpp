#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
            if (carry == 0) {
                break;
            }
        }
        if (carry != 0) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::vector<int> nums1 = {9};
    auto res1 = s.plusOne(nums1);
    for (int n : res1) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::vector<int> nums2 = {1, 2, 3};
    auto res2 = s.plusOne(nums2);
    for (int n : res2) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
