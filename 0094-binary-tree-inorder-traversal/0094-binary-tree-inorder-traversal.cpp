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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;
        stack<TreeNode*> pendingNodes;
        TreeNode* currentNode = root;

        while (currentNode != nullptr || !pendingNodes.empty()) {
            while (currentNode != nullptr) {
                pendingNodes.push(currentNode);
                currentNode = currentNode->left;
            }

            currentNode = pendingNodes.top();
            pendingNodes.pop();

            traversal.push_back(currentNode->val);
            currentNode = currentNode->right;
        }

        return traversal;
    }
};