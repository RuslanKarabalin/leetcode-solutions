#include <iostream>

class Solution {
   public:
    int sum(int num1, int num2) { return num1 + num2; }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::cout << (s.sum(1, 2) == 3) << std::endl;

    return 0;
}
