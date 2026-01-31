#include <iostream>
#include <string>

class Solution {
   public:
    bool isMatch(std::string text, std::string pattern) {
        if (pattern.empty()) {
            return text.empty();
        }
        bool firstMatch =
            (!text.empty() && (pattern[0] == text[0] || pattern[0] == '.'));

        if (pattern.length() >= 2 && pattern[1] == '*') {
            return (isMatch(text, pattern.substr(2)) ||
                    (firstMatch && isMatch(text.substr(1), pattern)));
        } else {
            return (firstMatch && isMatch(text.substr(1), pattern.substr(1)));
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::cout << std::boolalpha;
    std::cout << s.isMatch("aa", "a*") << std::endl;

    return 0;
}
