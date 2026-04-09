#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    int numberOfArrays(std::vector<int>& differences, int lower, int upper) {
        long long x = 0;
        long long y = 0;
        long long cur = 0;
        for (int d : differences) {
            cur += d;
            x = std::min(x, cur);
            y = std::max(y, cur);
            if (y - x > upper - lower) {
                return 0;
            }
        }
        return (upper - lower) - (int)(y - x) + 1;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::vector<int> d1 = {3, -4, 5, 1, -2};
    std::cout << s.numberOfArrays(d1, -4, 5) << std::endl;

    std::vector<int> d2 = {-40};
    std::cout << s.numberOfArrays(d2, -46, 53) << std::endl;

    std::vector<int> d3 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::cout << s.numberOfArrays(d3, -2, 2) << std::endl;

    return 0;
}
