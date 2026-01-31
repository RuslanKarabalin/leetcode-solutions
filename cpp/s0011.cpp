#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxSquare = 0;

        while (left < right) {
            int width = right - left;
            int h = std::min(height[left], height[right]);
            int area = h * width;
            maxSquare = std::max(maxSquare, area);

            if (height[left] < height[right]) {
                left++;
            } else if (height[left] > height[right]) {
                right--;
            } else {
                left++;
                right--;
            }
        }

        return maxSquare;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    std::vector<int> h0 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << s.maxArea(h0) << std::endl;

    return 0;
}
