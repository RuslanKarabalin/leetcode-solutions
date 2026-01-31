#include <iostream>
#include <string>

class Solution {
   public:
    std::string longestPalindrome(std::string s) {
        int len = s.length();
        if (len == 1) {
            return s;
        }
        int resStart = 0;
        int resLen = 0;
        for (int i = len; i >= 1; --i) {
            for (int j = 0; j <= len - i; ++j) {
                if (isPalindrome(s, j, j + i - 1)) {
                    resStart = j;
                    resLen = i;
                    break;
                }
            }
            if (resLen != 0) {
                break;
            }
        }
        return s.substr(resStart, resLen);
    }

   private:
    bool isPalindrome(const std::string& s, int l, int r) {
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
