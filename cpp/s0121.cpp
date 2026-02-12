#include <iostream>
#include <vector>

class Solution {
   public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty())
            return 0;

        int maxProfit = 0;
        int buy = prices[0];

        for (size_t i = 1; i < prices.size(); ++i) {
            if (prices[i] < buy) {
                buy = prices[i];
            } else {
                int profit = prices[i] - buy;
                if (profit > maxProfit) {
                    maxProfit = profit;
                }
            }
        }

        return maxProfit;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    std::vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    std::cout << s.maxProfit(prices1) << std::endl;

    std::vector<int> prices2 = {7, 6, 4, 3, 1};
    std::cout << s.maxProfit(prices2) << std::endl;

    return 0;
}
