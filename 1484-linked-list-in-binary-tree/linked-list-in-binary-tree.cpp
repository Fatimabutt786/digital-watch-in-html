#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        return dfs(root, head);
    }

private:
    bool dfs(TreeNode* node, ListNode* head) {
        if (!node) return false;
        return match(node, head) || dfs(node->left, head) || dfs(node->right, head);
    }

    bool match(TreeNode* node, ListNode* head) {
        if (!head) return true; // Reached end of the linked list
        if (!node) return false; // Reached end of the binary tree without matching all linked list nodes
        
        if (node->val != head->val) return false; // Values do not match

        // Continue to match the rest of the linked list with the left and right subtree
        return match(node->left, head->next) || match(node->right, head->next);
    }
};
