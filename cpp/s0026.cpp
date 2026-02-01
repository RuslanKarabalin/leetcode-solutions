#include <iostream>
#include <set>
#include <vector>

class Solution {
   public:
    int removeDuplicates(std::vector<int>& nums) {
        std::set<int> s;
        for (int e : nums) {
            s.insert(e);
        }
        int i = 0;
        for (int e : s) {
            nums[i++] = e;
        }
        return s.size();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    std::cout << s.removeDuplicates(nums) << std::endl;

    return 0;
}
