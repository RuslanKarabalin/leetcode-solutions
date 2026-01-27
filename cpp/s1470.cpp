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
    std::vector<int> shuffle(std::vector<int>& nums, int n) {
        std::vector<int> res(2 * n);
        for (int i = 0; i < n; ++i) {
            res[2 * i] = nums[i];
        }
        for (int i = 0; i < n; ++i) {
            res[2 * i + 1] = nums[n + i];
        }
        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::vector<int> in0 = {2, 5, 1, 3, 4, 7};
    int n0 = 3;
    std::cout << s.shuffle(in0, n0) << std::endl;

    std::vector<int> in1 = {1, 2, 3, 4, 4, 3, 2, 1};
    int n1 = 4;
    std::cout << s.shuffle(in1, n1) << std::endl;

    std::vector<int> in2 = {1, 1, 2, 2};
    int n2 = 2;
    std::cout << s.shuffle(in2, n2) << std::endl;

    return 0;
}
