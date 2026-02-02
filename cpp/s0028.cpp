#include <iostream>
#include <string>

class Solution {
   public:
    int strStr(std::string haystack, std::string needle) {
        if (haystack.length() < needle.length()) {
            return -1;
        }
        int l = haystack.length() - needle.length();
        for (int i = 0; i <= l; ++i) {
            std::string sub = haystack.substr(i, needle.length());
            if (sub == needle) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::cout << (s.strStr("sadbutsad", "sad") == 0) << std::endl;
    std::cout << (s.strStr("leetcode", "leeto") == -1) << std::endl;
    std::cout << (s.strStr("a", "a") == 0) << std::endl;

    return 0;
}
