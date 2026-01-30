#include <iostream>
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
    int minimumOperations(std::vector<int>& nums) {
        int res = 0;
        for (int num : nums) {
            int rem = num % 3;
            res += rem == 2 ? 1 : rem;
        }
        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::vector<int> in0 = {1, 2, 3, 4};
    std::cout << s.minimumOperations(in0) << std::endl;

    return 0;
}
