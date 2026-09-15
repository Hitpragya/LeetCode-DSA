class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string currentPath;

        collectPaths(root, currentPath, paths);

        return paths;
    }

private:
    void collectPaths(TreeNode* node, string& currentPath, vector<string>& paths) {
        if (node == nullptr) {
            return;
        }

        int previousLength = currentPath.size();

        if (!currentPath.empty()) {
            currentPath += "->";
        }

        currentPath += to_string(node->val);

        if (node->left == nullptr && node->right == nullptr) {
            paths.push_back(currentPath);
        } else {
            collectPaths(node->left, currentPath, paths);
            collectPaths(node->right, currentPath, paths);
        }

        currentPath.resize(previousLength);
    }
};