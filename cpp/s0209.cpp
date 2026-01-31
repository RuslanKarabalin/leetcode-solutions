#include <climits>
#include <iostream>
#include <vector>

class Solution {
   public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0] >= target ? 1 : 0;
        }

        std::vector<int> prefSum;
        prefSum.push_back(0);
        for (int i = 0; i < n; ++i) {
            prefSum.push_back(nums[i] + prefSum[i]);
        }

        int minLen = INT_MAX;
        for (int i = n; i > 0; --i) {
            int l = 0;
            int h = i;
            while (l <= h) {
                int m = l + (h - l) / 2;
                int sum = prefSum[i] - prefSum[m];
                if (sum >= target) {
                    int len = i - m;
                    minLen = std::min(len, minLen);
                    l = m + 1;
                } else {
                    h = m - 1;
                }
            }
        }

        if (minLen == INT_MAX) {
            minLen = 0;
        }
        return minLen;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    int tr0 = 7;
    std::vector<int> in0 = {2, 3, 1, 2, 4, 3};

    std::cout << s.minSubArrayLen(tr0, in0) << std::endl;

    int tr1 = 11;
    std::vector<int> in1 = {1, 1, 1, 1, 1, 1, 1, 1};

    std::cout << s.minSubArrayLen(tr1, in1) << std::endl;

    int tr2 = 15;
    std::vector<int> in2 = {5, 1, 3, 5, 10, 7, 4, 9, 2, 8};

    std::cout << s.minSubArrayLen(tr2, in2) << std::endl;

    return 0;
}
