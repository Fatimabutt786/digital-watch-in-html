class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Create a set from the vector nums for quick lookup
        unordered_set<int> toRemove(nums.begin(), nums.end());
        
        // Create a dummy node to handle edge cases
        ListNode dummy(0);
        dummy.next = head;
        ListNode* current = &dummy;
        
        // Traverse the list and remove nodes
        while (current->next != nullptr) {
            if (toRemove.find(current->next->val) != toRemove.end()) {
                // Remove the node by changing the next pointer
                ListNode* nodeToDelete = current->next;
                current->next = current->next->next;
                delete nodeToDelete; // Free the memory of the removed node
            } else {
                // Move to the next node
                current = current->next;
            }
        }
        
        // Return the head of the modified list
        return dummy.next;
    }
};