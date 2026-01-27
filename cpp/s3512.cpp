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
    int minOperations(std::vector<int>& nums, int k) {
        int res = 0;
        for (int num : nums) {
            res += num;
        }
        return res % k;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    int k0 = 5;
    std::vector<int> in0 = {3, 9, 7};

    std::cout << s.minOperations(in0, k0) << std::endl;

    return 0;
}
