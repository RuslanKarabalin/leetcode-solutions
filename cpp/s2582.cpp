#include <iostream>

class Solution {
   public:
    int passThePillow(int n, int time) {
        int p = time % (2 * n - 2);
        if (p > n - 1) {
            return n - (p - n + 1);
        } else {
            return p + 1;
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::cout << s.passThePillow(4, 5) << std::endl;
    std::cout << s.passThePillow(3, 2) << std::endl;

    return 0;
}
