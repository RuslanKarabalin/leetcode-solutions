#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixSum;

        prefixSum.push_back(0);
        for (int i = 0; i < n; ++i) {
            prefixSum.push_back(nums[i] + prefixSum[i]);
        }

        for (int i = 0; i < n; ++i) {
            int lSum = 0;
            int rSum = 0;
            lSum = prefixSum[i];
            rSum = prefixSum[n] - prefixSum[i + 1];
            if (lSum == rSum) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> in0 = {1, 7, 3, 6, 5, 6};
    vector<int> in1 = {1, 2, 3};
    vector<int> in2 = {2, 1, -1};

    Solution s;

    cout << s.pivotIndex(in0) << "\n";
    cout << s.pivotIndex(in1) << "\n";
    cout << s.pivotIndex(in2) << "\n";

    return 0;
}
