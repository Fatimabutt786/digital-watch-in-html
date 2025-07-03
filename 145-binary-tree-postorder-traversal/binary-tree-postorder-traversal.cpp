
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return{};
        stack<TreeNode*> st;
        vector<int> result;

        st.push(root);
        while(!st.empty()){
            TreeNode*node=st.top();
            st.pop();
            result.push_back(node->val);
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};