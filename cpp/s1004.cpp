#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0;
        int r = 0;
        int flips = 0;
        int maxLen = 0;
        while (r < n) {
            if (nums[r] == 0) {
                if (flips < k) {
                    ++r;
                    ++flips;
                } else {
                    int len = r - l;
                    maxLen = max(len, maxLen);
                    if (nums[l] == 0) {
                        --flips;
                    }
                    ++l;
                }
            } else {
                ++r;
            }
        }
        return max(r - l, maxLen);
        ;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;

    vector<int> in0 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k0 = 2;
    cout << s.longestOnes(in0, k0) << std::endl;

    vector<int> in1 = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k1 = 3;
    cout << s.longestOnes(in1, k1) << std::endl;

    vector<int> in2 = {0, 0, 0, 1};
    int k2 = 4;
    cout << s.longestOnes(in2, k2) << std::endl;

    return 0;
}
