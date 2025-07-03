
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return{};
        vector<int> left=preorderTraversal(root->left);
        vector<int> right=preorderTraversal(root->right);
        vector<int> result={root->val};
        result.insert(result.end(),left.begin(),left.end());
        result.insert(result.end(),right.begin(),right.end());
        return result;  
    }
};