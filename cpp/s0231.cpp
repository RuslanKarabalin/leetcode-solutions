#include <iostream>

class Solution {
   public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        return (n & (n - 1)) == 0;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::cout << std::boolalpha;
    std::cout << s.isPowerOfTwo(16) << std::endl;
    std::cout << s.isPowerOfTwo(18) << std::endl;
    std::cout << s.isPowerOfTwo(1) << std::endl;
    std::cout << s.isPowerOfTwo(0) << std::endl;
    std::cout << s.isPowerOfTwo(-2) << std::endl;

    return 0;
}
