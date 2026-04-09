#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
   public:
    std::string customSortString(std::string order, std::string s) {
        std::unordered_map<char, int> freqMap;
        std::string notInOrder;

        for (char c : s) {
            if (order.find(c) != std::string::npos) {
                freqMap[c]++;
            } else {
                notInOrder += c;
            }
        }

        std::string result;
        for (char c : order) {
            if (freqMap.count(c)) {
                result += std::string(freqMap[c], c);
            }
        }

        result += notInOrder;
        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::cout << s.customSortString("cba", "abcd") << std::endl;

    return 0;
}
