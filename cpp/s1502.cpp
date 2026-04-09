#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

class Solution {
   public:
    bool canMakeArithmeticProgression(std::vector<int>& arr) {
        if (arr.size() <= 2)
            return true;
        std::sort(arr.begin(), arr.end());
        int d = std::abs(arr[0] - arr[1]);
        for (int i = 1; i < (int)arr.size() - 1; ++i) {
            if (std::abs(arr[i] - arr[i + 1]) != d)
                return false;
        }
        return true;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::vector<int> a1 = {3, 5, 1};
    std::cout << s.canMakeArithmeticProgression(a1) << std::endl;

    std::vector<int> a2 = {1, 2, 4};
    std::cout << s.canMakeArithmeticProgression(a2) << std::endl;

    return 0;
}
