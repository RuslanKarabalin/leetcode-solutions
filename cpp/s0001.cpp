#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> rem_to_index;
        for (int i = 0; i < nums.size(); ++i) {
            int rem = target - nums[i];
            unordered_map<int, int>::iterator o = rem_to_index.find(rem);
            if (o != rem_to_index.end()) {
                return {i, o->second};
            } else {
                rem_to_index[nums[i]] = i;
            }
        }
        return {-1, -1};
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    vector<int> in = vector<int>{2, 7, 11, 15};
    vector<int> res = s.twoSum(in, 9);

    for (auto x : res) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
