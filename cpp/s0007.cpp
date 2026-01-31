#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <string>

class Solution {
   public:
    int reverse(int x) {
        bool isNegative = x < 0;
        long long absX = std::abs((long long)x);
        std::string absStr = std::to_string(absX);
        std::reverse(absStr.begin(), absStr.end());
        long long reversedLong = std::stoll(absStr);

        long long result = isNegative ? -reversedLong : reversedLong;

        if (result < INT_MIN || result > INT_MAX) {
            return 0;
        }
        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::cout << s.reverse(123) << std::endl;
    std::cout << s.reverse(-456) << std::endl;
    std::cout << s.reverse(1534236469) << std::endl;
    std::cout << s.reverse(-2147483648) << std::endl;

    return 0;
}
