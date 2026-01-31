#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        if (n == 0) {
            return res;
        }
        if (n == 1) {
            return nums;
        }
        res.push_back(nums[0]);
        for (int i = 1; i < n; ++i) {
            res.push_back(nums[i] + res[i - 1]);
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;

    vector<int> in0 = {3, 1, 2, 10, 1};
    vector<int> res = s.runningSum(in0);
    for (int x : res) {
        cout << x << " ";
    }
    cout << std::endl;

    return 0;
}
