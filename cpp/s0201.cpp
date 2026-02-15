#include <iostream>

class Solution {
   public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;

        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }

        return left << shift;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::cout << s.rangeBitwiseAnd(5, 7) << std::endl;
    std::cout << s.rangeBitwiseAnd(0, 1) << std::endl;
    std::cout << s.rangeBitwiseAnd(10, 11) << std::endl;

    return 0;
}
