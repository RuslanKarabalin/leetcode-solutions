#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

class Solution {
   public:
    bool isValid(std::string s) {
        if (s.length() % 2 == 1) {
            return false;
        }
        std::unordered_map<char, char> map = {
            {'(', ')'}, {'{', '}'}, {'[', ']'}};
        std::stack<char> stack;
        for (char c : s) {
            auto it = map.find(c);
            if (it == map.end()) {
                if (stack.empty()) {
                    return false;
                }
                char ct = map[stack.top()];
                if (c != ct) {
                    return false;
                } else {
                    stack.pop();
                }
            } else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::cout << std::boolalpha;
    std::cout << s.isValid("()[]{}") << std::endl;
    std::cout << s.isValid("(}") << std::endl;
    std::cout << s.isValid("){") << std::endl;
    std::cout << s.isValid(")") << std::endl;

    return 0;
}
