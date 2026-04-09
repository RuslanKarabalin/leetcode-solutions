#include <algorithm>
#include <iostream>
#include <string>

class Solution {
   public:
    std::string toLowerCase(std::string s) {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::cout << (s.toLowerCase("Hello") == "hello") << std::endl;

    return 0;
}
