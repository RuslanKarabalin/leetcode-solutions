#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int h = n - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (target < nums[m]) {
                h = m - 1;
            } else if (target > nums[m]) {
                l = m + 1;
            } else {
                return m;
            }
        }
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> in0 = {-1, 0, 3, 5, 9, 12};
    int t0 = 9;

    vector<int> in1 = {-1, 0, 3, 5, 9, 12};
    int t1 = 2;

    Solution s;

    cout << s.search(in0, t0) << std::endl;
    cout << s.search(in1, t1) << std::endl;

    return 0;
}
