#include <iostream>
#include <vector>

class Solution {
   public:
    bool threeConsecutiveOdds(std::vector<int>& arr) {
        for (int i = 0; i < (int)arr.size() - 2; ++i) {
            if (arr[i] % 2 != 0 && arr[i + 1] % 2 != 0 && arr[i + 2] % 2 != 0) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::vector<int> a1 = {2, 6, 4, 1, 3, 5};
    std::cout << s.threeConsecutiveOdds(a1) << std::endl;

    std::vector<int> a2 = {1, 2, 34, 3, 4, 5, 7, 23, 12};
    std::cout << s.threeConsecutiveOdds(a2) << std::endl;

    std::vector<int> a3 = {2, 4, 6, 8};
    std::cout << s.threeConsecutiveOdds(a3) << std::endl;

    return 0;
}
