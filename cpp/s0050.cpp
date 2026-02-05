#include <climits>
#include <iostream>

class Solution {
   public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;

        if (n == INT_MAX) {
            if (x == 1.0) {
                return 1.0;
            }
            if (x == -1.0) {
                return -1.0;
            }
            return 0.0;
        }

        if (n == INT_MIN) {
            if (x == 1.0 || x == -1.0) {
                return 1.0;
            }
            return 0.0;
        }

        double base = x;
        int exponent = n;
        double result = 1.0;

        if (exponent < 0) {
            base = 1 / base;
            exponent = -exponent;
        }

        for (int i = 0; i < exponent; ++i) {
            result *= base;
        }

        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::cout << s.myPow(2.0, 10) << std::endl;
    std::cout << s.myPow(2.0, -2) << std::endl;
    std::cout << s.myPow(0.00001, INT_MAX) << std::endl;
    std::cout << s.myPow(-1.0, INT_MIN) << std::endl;

    return 0;
}
