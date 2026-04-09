#include <iostream>
#include <queue>
#include <utility>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr)
            return 0;

        std::queue<std::pair<TreeNode*, bool>> queue;
        queue.push({root, false});
        int totalSum = 0;

        while (!queue.empty()) {
            auto [node, isLeft] = queue.front();
            queue.pop();

            if (isLeft && node->left == nullptr && node->right == nullptr) {
                totalSum += node->val;
            }

            if (node->left)
                queue.push({node->left, true});
            if (node->right)
                queue.push({node->right, false});
        }

        return totalSum;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    std::cout << s.sumOfLeftLeaves(root) << std::endl;

    return 0;
}
