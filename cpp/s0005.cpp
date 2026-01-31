#include <iostream>
#include <string>

class Solution {
   public:
    std::string longestPalindrome(std::string s) {
        std::string result = "";
        int len = s.length();
        if (len == 1) {
            return s;
        }
        for (int i = len; i >= 1; --i) {
            for (int j = 0; j <= len - i; ++j) {
                std::string subS = s.substr(j, i);
                if (isPalindrome(subS)) {
                    result = subS;
                    break;
                }
            }
            if (result != "") {
                break;
            }
        }
        return result;
    }

   private:
    bool isPalindrome(const std::string& s) {
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::cout << s.longestPalindrome("babad") << std::endl;
    std::cout << s.longestPalindrome("a") << std::endl;
    std::cout << s.longestPalindrome("bb") << std::endl;

    return 0;
}
