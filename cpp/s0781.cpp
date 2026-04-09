#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    int numRabbits(std::vector<int>& answers) {
        std::unordered_map<int, int> map;
        for (int a : answers) {
            map[a]++;
        }
        int count = 0;
        for (auto& [k, v] : map) {
            count += (int)std::ceil((double)v / (k + 1)) * (k + 1);
        }
        return count;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::vector<int> a1 = {1, 1, 2};
    std::cout << s.numRabbits(a1) << std::endl;

    std::vector<int> a2 = {10, 10, 10};
    std::cout << s.numRabbits(a2) << std::endl;

    std::vector<int> a3 = {1, 0, 1, 0, 0};
    std::cout << s.numRabbits(a3) << std::endl;

    std::vector<int> a4 = {0, 0, 1, 1, 1};
    std::cout << s.numRabbits(a4) << std::endl;

    std::vector<int> a5 = {2, 1, 2, 2, 2, 2, 2, 2, 1, 1};
    std::cout << s.numRabbits(a5) << std::endl;

    std::vector<int> a6 = {0, 3, 2, 0, 3, 3, 4, 2, 4, 3,
                           2, 4, 4, 3, 0, 1, 3, 4, 4, 3};
    std::cout << s.numRabbits(a6) << std::endl;

    return 0;
}
