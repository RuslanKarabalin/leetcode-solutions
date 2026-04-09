#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    bool stoneGame(std::vector<int>& piles) {
        std::sort(piles.begin(), piles.end());
        int a = 0;
        int b = 0;

        int i = 0;
        while (i < (int)piles.size() - 1) {
            b += piles[i++];
            a += piles[i++];
        }

        return a > b;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::vector<int> piles = {5, 3, 4, 5};
    std::cout << s.stoneGame(piles) << std::endl;

    return 0;
}
