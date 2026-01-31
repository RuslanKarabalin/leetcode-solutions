#include <algorithm>
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
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> result;

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int m = i + 1;
            int r = n - 1;

            while (m < r) {
                int currSum = nums[i] + nums[m] + nums[r];
                if (currSum == 0) {
                    std::vector<int> v = {nums[i], nums[m], nums[r]};
                    result.push_back(v);

                    while (m < r && nums[m] == nums[m + 1]) {
                        ++m;
                    }

                    while (m < r && nums[r] == nums[r - 1]) {
                        --r;
                    }

                    ++m;
                    --r;
                } else if (currSum > 0) {
                    --r;
                } else {
                    ++m;
                }
            }
        }

        return result;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::vector<int> in0 = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> re0 = s.threeSum(in0);

    for (std::vector<int> v : re0) {
        std::cout << v << std::endl;
    }

    return 0;
}
