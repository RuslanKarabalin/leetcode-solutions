#include <iostream>
#include <vector>

class Solution {
   public:
    int removeElement(std::vector<int>& nums, int val) {
        std::vector<int> arr;
        for (int e : nums) {
            if (e != val) {
                arr.push_back(e);
            }
        }
        for (int i = 0; i < arr.size(); ++i) {
            nums[i] = arr[i];
        }
        return arr.size();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    std::cout << s.removeElement(nums, 2) << std::endl;

    return 0;
}
