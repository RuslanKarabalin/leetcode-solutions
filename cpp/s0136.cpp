#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int x : nums) {
            res ^= x;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;

    vector<int> in = {4, 1, 2, 1, 2};
    cout << s.singleNumber(in) << "\n";

    return 0;
}
