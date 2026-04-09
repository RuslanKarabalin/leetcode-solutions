#include <iostream>

class Solution {
   public:
    int numberOfSteps(int num) {
        int steps = 0;
        while (num != 0) {
            if (num % 2 == 0) {
                num /= 2;
            } else {
                num -= 1;
            }
            steps++;
        }
        return steps;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::cout << s.numberOfSteps(14) << std::endl;
    std::cout << s.numberOfSteps(8) << std::endl;
    std::cout << s.numberOfSteps(123) << std::endl;

    return 0;
}
