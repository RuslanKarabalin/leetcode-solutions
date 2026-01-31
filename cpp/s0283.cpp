#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int zero = -1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            int l = i;
            int r = i + 1;
            if (nums[l] == 0) {
                while (r < nums.size() && nums[r] == 0) {
                    ++r;
                }
                if (r < nums.size() && nums[r] != 0) {
                    nums[l] = nums[r];
                    nums[r] = 0;
                }
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v = {0, 1, 0, 3, 12};

    Solution s;
    s.moveZeroes(v);
    for (int x : v) {
        cout << x << " ";
    }
    cout << std::endl;

    return 0;
}
