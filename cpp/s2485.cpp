#include <iostream>

class Solution {
   public:
    int pivotInteger(int n) {
        for (int i = 1; i <= n; ++i) {
            int prefixSum = (1 + i) * i / 2;
            int suffixSum = (i + n) * (n - i + 1) / 2;
            if (prefixSum == suffixSum) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::cout << s.pivotInteger(8) << std::endl;
    std::cout << s.pivotInteger(1) << std::endl;
    std::cout << s.pivotInteger(4) << std::endl;

    return 0;
}
