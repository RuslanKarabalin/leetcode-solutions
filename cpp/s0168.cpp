#include <iostream>
#include <string>

class Solution {
   public:
    std::string convertToTitle(int columnNumber) {
        std::string result;

        while (columnNumber != 0) {
            columnNumber--;
            char c = 'A' + (columnNumber % 26);
            result.insert(result.begin(), c);
            columnNumber /= 26;
        }

        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::cout << s.convertToTitle(1) << std::endl;
    std::cout << s.convertToTitle(28) << std::endl;
    std::cout << s.convertToTitle(701) << std::endl;
    std::cout << s.convertToTitle(2147483647) << std::endl;

    return 0;
}
