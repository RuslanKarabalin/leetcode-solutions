#include <iostream>
#include <string>
#include <vector>

class Solution {
   public:
    int countSeniors(std::vector<std::string>& details) {
        int result = 0;
        for (const auto& s : details) {
            int age = std::stoi(s.substr(11, 2));
            if (age > 60) {
                result++;
            }
        }
        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::vector<std::string> details = {"7868190130M7522", "5303914400F9211",
                                        "9273338290F4010"};
    std::cout << s.countSeniors(details) << std::endl;

    return 0;
}
