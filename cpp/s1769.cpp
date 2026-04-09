#include <cmath>
#include <iostream>
#include <string>
#include <vector>

class Solution {
   public:
    std::vector<int> minOperations(std::string boxes) {
        int n = boxes.size();
        std::vector<std::vector<int>> map(n, std::vector<int>(n, 0));

        for (int i = 0; i < n; ++i) {
            if (boxes[i] == '1') {
                for (int j = 0; j < n; ++j) {
                    map[i][j] = std::abs(j - i);
                }
            }
        }

        std::vector<int> result(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result[j] += map[i][j];
            }
        }

        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    auto r1 = s.minOperations("110");
    for (int x : r1)
        std::cout << x << " ";
    std::cout << std::endl;

    auto r2 = s.minOperations("001011");
    for (int x : r2)
        std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
