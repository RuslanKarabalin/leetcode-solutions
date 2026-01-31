#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return nums[0] < nums[1] ? nums[0] : nums[1];
        }

        int minVal = INT_MAX;
        int l = 0;
        int h = n - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m] < minVal) {
                minVal = nums[m];
            }

            int mv = nums[m];
            int hv = nums[h];

            if (mv > hv) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return minVal;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;

    vector<int> in0 = {3, 4, 5, 1, 2};
    vector<int> in1 = {4, 5, 6, 7, 0, 1, 2};
    vector<int> in2 = {11, 13, 15, 17};
    vector<int> in3 = {2, 3, 4, 5, 1};
    vector<int> in4 = {5, 1, 2, 3, 4};
    vector<int> in5 = {3, 1, 2};

    cout << s.findMin(in0) << std::endl;
    cout << s.findMin(in1) << std::endl;
    cout << s.findMin(in2) << std::endl;
    cout << s.findMin(in3) << std::endl;
    cout << s.findMin(in4) << std::endl;
    cout << s.findMin(in5) << std::endl;

    return 0;
}
