#include <iostream>
#include <string>
#include <vector>

class Solution {
   public:
    bool arrayStringsAreEqual(std::vector<std::string>& word1,
                              std::vector<std::string>& word2) {
        std::string s1, s2;
        for (const auto& w : word1)
            s1 += w;
        for (const auto& w : word2)
            s2 += w;
        return s1 == s2;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::vector<std::string> word1 = {"abc", "d", "defg"};
    std::vector<std::string> word2 = {"abcddefg"};
    std::cout << s.arrayStringsAreEqual(word1, word2) << std::endl;

    return 0;
}
