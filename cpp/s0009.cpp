#include <iostream>
#include <string>

class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        std::string str = std::to_string(x);
        int len = str.length();
        for (int i = 0; i < len / 2; ++i) {
            if (str[i] != str[len - i - 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::cout << std::boolalpha;
    std::cout << s.isPalindrome(123321) << std::endl;
    std::cout << s.isPalindrome(12321) << std::endl;
    std::cout << s.isPalindrome(12345) << std::endl;
    std::cout << s.isPalindrome(-121) << std::endl;

    return 0;
}
