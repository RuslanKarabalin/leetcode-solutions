#include <iostream>
#include <string>
#include <vector>

class Solution {
   public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) {
            return "";
        }

        size_t minLength = strs[0].length();
        for (size_t i = 1; i < strs.size(); ++i) {
            if (strs[i].length() < minLength) {
                minLength = strs[i].length();
            }
        }

        std::string result;
        for (size_t i = 0; i < minLength; ++i) {
            char currentChar = strs[0][i];
            for (size_t j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != currentChar) {
                    return result;
                }
            }
            result += currentChar;
        }

        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::vector<std::string> strs = {"flower", "flow", "flight"};
    std::cout << s.longestCommonPrefix(strs) << std::endl;

    return 0;
}
