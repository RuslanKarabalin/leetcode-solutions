#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
    out << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        const auto& x = v[i];
        out << x;
        if (i < v.size() - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

class Solution {
   public:
    std::string intToRoman(int num) {
        std::vector<int> ints = {
            1000, 900, 800, 700, 600, 500, 400, 300, 200, 100, 90, 80, 70, 60,
            50,   40,  30,  20,  10,  9,   8,   7,   6,   5,   4,  3,  2,  1};

        std::unordered_map<int, std::string> m = {
            {1000, "M"}, {900, "CM"},  {800, "DCCC"}, {700, "DCC"}, {600, "DC"},
            {500, "D"},  {400, "CD"},  {300, "CCC"},  {200, "CC"},  {100, "C"},
            {90, "XC"},  {80, "LXXX"}, {70, "LXX"},   {60, "LX"},   {50, "L"},
            {40, "XL"},  {30, "XXX"},  {20, "XX"},    {10, "X"},    {9, "IX"},
            {8, "VIII"}, {7, "VII"},   {6, "VI"},     {5, "V"},     {4, "IV"},
            {3, "III"},  {2, "II"},    {1, "I"}};

        std::stringstream strStream;
        for (int i : ints) {
            int rem = num / i;
            std::string s = m[i];
            num -= rem * i;
            for (int i = 0; i < rem; ++i) {
                strStream << s;
            }
        }

        return strStream.str();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::cout << s.intToRoman(3749) << std::endl;

    return 0;
}
