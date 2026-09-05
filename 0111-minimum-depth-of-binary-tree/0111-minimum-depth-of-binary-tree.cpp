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
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> nodes;
        nodes.push(root);
        int depth = 1;

        while (!nodes.empty()) {
            int levelSize = nodes.size();

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = nodes.front();
                nodes.pop();

                if (currentNode->left == nullptr && currentNode->right == nullptr) {
                    return depth;
                }

                if (currentNode->left != nullptr) {
                    nodes.push(currentNode->left);
                }

                if (currentNode->right != nullptr) {
                    nodes.push(currentNode->right);
                }
            }

            ++depth;
        }

        return depth;
    }
};