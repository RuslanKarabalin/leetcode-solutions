#include <iostream>
#include <string>

class Solution {
   public:
    int lengthOfLastWord(std::string s) {
        int i = s.length() - 1;
        while (i >= 0 && s[i] == ' ') {
            --i;
        }
        int end = i;
        while (i >= 0 && s[i] != ' ') {
            --i;
        }
        return end - i;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::cout << (s.lengthOfLastWord("Hello World") == 5) << std::endl;
    std::cout << (s.lengthOfLastWord("   fly me   to   the moon  ") == 4)
              << std::endl;
    std::cout << (s.lengthOfLastWord("luffy is still joyboy") == 6)
              << std::endl;

    return 0;
}
