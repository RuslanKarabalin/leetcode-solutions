#include <iostream>
#include <string>

class Solution {
   public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        if (ransomNote.length() > magazine.length())
            return false;

        for (char c : magazine) {
            size_t index = ransomNote.find(c);
            if (index != std::string::npos) {
                ransomNote.erase(index, 1);
            }
        }

        return ransomNote.empty();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::cout << s.canConstruct("fihjjjjei", "hjibagacbhadfaefdjaeaebgi")
              << std::endl;
    std::cout << s.canConstruct("aa", "aab") << std::endl;

    return 0;
}
