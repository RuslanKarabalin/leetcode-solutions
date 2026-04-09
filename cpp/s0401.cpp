#include <iostream>
#include <string>
#include <vector>

class Solution {
   public:
    std::vector<std::string> readBinaryWatch(int turnedOn) {
        std::vector<std::string> times;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (__builtin_popcount(h * 64 + m) == turnedOn) {
                    std::string time = std::to_string(h) + ":";
                    if (m < 10)
                        time += "0";
                    time += std::to_string(m);
                    times.push_back(time);
                }
            }
        }
        return times;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    auto result = s.readBinaryWatch(1);
    for (const auto& t : result) {
        std::cout << t << " ";
    }
    std::cout << std::endl;

    return 0;
}
