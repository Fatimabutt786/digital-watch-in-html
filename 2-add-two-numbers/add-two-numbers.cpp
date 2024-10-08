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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy head to simplify the result list creation
        ListNode dummy(0);
        ListNode* current = &dummy; // Pointer to construct the result list
        int carry = 0; // Initialize carry to 0

        // Traverse both lists
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry; // Start with the carry

            // Add the value from the first list if available
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next; // Move to the next node in l1
            }

            // Add the value from the second list if available
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next; // Move to the next node in l2
            }

            // Update carry and the new digit to add to the result list
            carry = sum / 10; // Calculate new carry
            current->next = new ListNode(sum % 10); // Create a new node with the sum's last digit
            current = current->next; // Move to the newly created node
        }

        // The result list is after the dummy node
        return dummy.next; 
    }
};
