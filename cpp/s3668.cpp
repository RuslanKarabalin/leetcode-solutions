#include <iostream>
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
    std::vector<int> recoverOrder(std::vector<int>& order,
                                  std::vector<int>& friends) {
        std::unordered_set<int> fset;
        for (int f : friends) {
            fset.insert(f);
        }
        std::vector<int> res;
        for (int o : order) {
            std::unordered_set<int>::iterator it = fset.find(o);
            if (it != fset.end()) {
                res.push_back(o);
            }
        }
        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::vector<int> order0 = {3, 1, 2, 5, 4};
    std::vector<int> friends0 = {1, 3, 4};
    std::cout << s.recoverOrder(order0, friends0) << std::endl;

    return 0;
}
