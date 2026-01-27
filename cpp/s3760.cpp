#include <iostream>
#include <string>
#include <unordered_set>
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
    int maxDistinct(std::string s) {
        std::unordered_set<char> chars;
        for (char c : s) {
            chars.insert(c);
        }
        return chars.size();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    return 0;
}
