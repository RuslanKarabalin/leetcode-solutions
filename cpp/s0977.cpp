#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        if (n == 0) {
            return res;
        }
        if (n == 1) {
            res.push_back(nums[0] * nums[0]);
            return res;
        }

        int l = 0;
        int r = n - 1;
        while (l <= r) {
            int ln2 = nums[l] * nums[l];
            int rn2 = nums[r] * nums[r];
            if (ln2 > rn2) {
                res.push_back(ln2);
                ++l;
            } else {
                res.push_back(rn2);
                --r;
            }
        }

        l = 0;
        r = res.size() - 1;
        while (l < r) {
            int tmp = res[r];
            res[r] = res[l];
            res[l] = tmp;
            ++l;
            --r;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;

    vector<int> in = vector<int>{-7, -3, 2, 3, 11};
    vector<int> res = s.sortedSquares(in);

    for (auto x : res) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
