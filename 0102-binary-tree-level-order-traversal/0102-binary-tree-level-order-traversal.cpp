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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;

        if (root == nullptr) {
            return levels;
        }

        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);

        while (!pendingNodes.empty()) {
            int nodesInCurrentLevel = pendingNodes.size();
            vector<int> currentLevel;

            for (int index = 0; index < nodesInCurrentLevel; ++index) {
                TreeNode* currentNode = pendingNodes.front();
                pendingNodes.pop();

                currentLevel.push_back(currentNode->val);

                if (currentNode->left != nullptr) {
                    pendingNodes.push(currentNode->left);
                }

                if (currentNode->right != nullptr) {
                    pendingNodes.push(currentNode->right);
                }
            }

            levels.push_back(currentLevel);
        }

        return levels;
    }
};