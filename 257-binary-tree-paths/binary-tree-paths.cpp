class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (root != nullptr) {
            dfs(root, "", paths);
        }
        return paths;
    }
    
private:
    void dfs(TreeNode* node, string path, vector<string>& paths) {
        if (node == nullptr) return;
        
        // Append the current node's value to the path
        path += to_string(node->val);
        
        // If it's a leaf node, add the path to the result
        if (node->left == nullptr && node->right == nullptr) {
            paths.push_back(path);
        } else {
            // Otherwise, continue DFS on the children
            path += "->"; // Add separator for the next node
            if (node->left != nullptr) {
                dfs(node->left, path, paths);
            }
            if (node->right != nullptr) {
                dfs(node->right, path, paths);
            }
        }
    }
};