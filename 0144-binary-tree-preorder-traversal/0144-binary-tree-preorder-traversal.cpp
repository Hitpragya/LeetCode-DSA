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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> traversal;
        if (root == nullptr) {
            return traversal;
        }

        stack<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            TreeNode* currentNode = nodes.top();
            nodes.pop();

            traversal.push_back(currentNode->val);

            if (currentNode->right != nullptr) {
                nodes.push(currentNode->right);
            }

            if (currentNode->left != nullptr) {
                nodes.push(currentNode->left);
            }
        }

        return traversal;
    }
};