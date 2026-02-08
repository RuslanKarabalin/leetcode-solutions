#include <iostream>

class Solution {
   public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int n1 = 1;
        int n2 = 2;

        for (int i = 3; i <= n; ++i) {
            int tmp = n1;
            n1 = n2;
            n2 += tmp;
        }

        return n2;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::cout << s.climbStairs(44) << std::endl;

    return 0;
}
