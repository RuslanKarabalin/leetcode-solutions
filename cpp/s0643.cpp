#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) {
            return .0;
        }
        if (n == 1) {
            return (double)nums[0] / k;
        }
        if (n < k) {
            double sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += nums[i];
            }
            return sum / k;
        }

        double sum = 0;
        double maxSum = INT_MIN;
        int l = 0;
        int r = 0;
        while (r <= n) {
            while (r - l < k) {
                sum += nums[r++];
            }
            maxSum = max(sum, maxSum);
            sum -= nums[l++];
            sum += nums[r++];
        }

        return maxSum / k;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;

    vector<int> in0 = {1, 12, -5, -6, 50, 3};
    int t0 = 4;

    cout << s.findMaxAverage(in0, t0) << std::endl;

    vector<int> in1 = {5};
    int t1 = 1;

    cout << s.findMaxAverage(in1, t1) << std::endl;

    return 0;
}
