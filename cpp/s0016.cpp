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
    int threeSumClosest(std::vector<int>& nums, int target) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());

        int bestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; ++i) {
            int m = i + 1;
            int r = n - 1;

            while (m < r) {
                int currSum = nums[i] + nums[m] + nums[r];

                if (std::abs(currSum - target) < std::abs(bestSum - target)) {
                    bestSum = currSum;
                }

                if (currSum < target) {
                    ++m;
                } else if (currSum > target) {
                    --r;
                } else {
                    return currSum;
                }
            }
        }

        return bestSum;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::vector<int> in0 = {-1, 2, 1, -4};
    int tr0 = 1;

    std::cout << s.threeSumClosest(in0, tr0) << std::endl;

    return 0;
}
