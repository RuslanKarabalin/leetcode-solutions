#include <iostream>
#include <vector>

class Solution {
   public:
    int subsetXORSum(std::vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for (int i = 0; i < (1 << n); ++i) {
            int subsetSum = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    subsetSum ^= nums[j];
                }
            }
            sum += subsetSum;
        }

        return sum;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::vector<int> a1 = {1, 3};
    std::cout << s.subsetXORSum(a1) << std::endl;

    std::vector<int> a2 = {5, 1, 6};
    std::cout << s.subsetXORSum(a2) << std::endl;

    std::vector<int> a3 = {3, 4, 5, 6, 7, 8};
    std::cout << s.subsetXORSum(a3) << std::endl;

    return 0;
}
