#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<double> convertTemperature(double celsius) {
        return {celsius + 273.15, celsius * 1.8 + 32};
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    auto result = s.convertTemperature(36.50);
    std::cout << result[0] << " " << result[1] << std::endl;

    return 0;
}
