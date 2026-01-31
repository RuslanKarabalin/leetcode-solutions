#include <algorithm>
#include <iostream>
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
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        std::vector<std::vector<int>> result;

        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int m = j + 1;
                int r = n - 1;

                while (m < r) {
                    long long currSum = 0;
                    currSum += nums[i];
                    currSum += nums[j];
                    currSum += nums[m];
                    currSum += nums[r];

                    if (currSum == target) {
                        result.push_back({nums[i], nums[j], nums[m], nums[r]});

                        while (m < r && nums[m] == nums[m + 1]) {
                            ++m;
                        }
                        while (m < r && nums[r] == nums[r - 1]) {
                            --r;
                        }

                        ++m;
                        --r;
                    } else if (currSum > target) {
                        --r;
                    } else {
                        ++m;
                    }
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

    int tr0 = 0;
    std::vector<int> in0 = {1, 0, -1, 0, -2, 2};
    std::vector<std::vector<int>> re0 = s.fourSum(in0, tr0);

    for (std::vector<int> v : re0) {
        std::cout << v << std::endl;
    }

    return 0;
}
