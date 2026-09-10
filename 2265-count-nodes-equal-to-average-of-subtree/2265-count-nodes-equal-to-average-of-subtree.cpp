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
    int matchingNodes = 0;

    pair<int, int> getSubtreeInfo(TreeNode* node) {
        if (node == nullptr) {
            return {0, 0};
        }

        auto [leftSum, leftCount] = getSubtreeInfo(node->left);
        auto [rightSum, rightCount] = getSubtreeInfo(node->right);

        int subtreeSum = leftSum + rightSum + node->val;
        int subtreeCount = leftCount + rightCount + 1;

        if (subtreeSum / subtreeCount == node->val) {
            matchingNodes++;
        }

        return {subtreeSum, subtreeCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        getSubtreeInfo(root);
        return matchingNodes;
    }
};