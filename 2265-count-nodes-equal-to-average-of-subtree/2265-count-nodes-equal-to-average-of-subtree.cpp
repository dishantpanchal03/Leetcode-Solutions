/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;

    pair<int, int> dfs(TreeNode* node) {
        if (!node)
            return {0, 0};

        auto [leftSum, leftCount] = dfs(node->left);
        auto [rightSum, rightCount] = dfs(node->right);

        int sum = leftSum + rightSum + node->val;
        int count = leftCount + rightCount + 1;

        if (sum / count == node->val)
            ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};