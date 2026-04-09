#include <iostream>

class Solution {
   public:
    int theMaximumAchievableX(int num, int t) { return (2 * t) + num; }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::cout << s.theMaximumAchievableX(4, 1) << std::endl;

    return 0;
}
