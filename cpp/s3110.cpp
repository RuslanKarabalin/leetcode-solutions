#include <cmath>
#include <iostream>
#include <string>

class Solution {
   public:
    int scoreOfString(std::string s) {
        int result = 0;
        for (int i = 0; i < (int)s.length() - 1; ++i) {
            result += std::abs(s[i] - s[i + 1]);
        }
        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::cout << s.scoreOfString("hello") << std::endl;
    std::cout << s.scoreOfString("zaz") << std::endl;

    return 0;
}
