class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Step 1: Calculate the length of the list
        int totalLength = 0;
        ListNode* current = head;
        while (current) {
            totalLength++;
            current = current->next;
        }
        
        // Step 2: Calculate the size of each part
        int baseSize = totalLength / k;
        int extraParts = totalLength % k;
        
        // Step 3: Split the list into parts
        vector<ListNode*> result(k, nullptr);
        current = head;
        for (int i = 0; i < k; ++i) {
            ListNode* partHead = nullptr;
            ListNode* partTail = nullptr;
            int partSize = baseSize + (i < extraParts ? 1 : 0);
            
            // Create the current part
            for (int j = 0; j < partSize; ++j) {
                if (!partHead) {
                    partHead = new ListNode(current->val);
                    partTail = partHead;
                } else {
                    partTail->next = new ListNode(current->val);
                    partTail = partTail->next;
                }
                current = current->next;
            }
            
            // Add the part to the result
            result[i] = partHead;
        }
        
        return result;
    }
};