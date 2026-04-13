class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both until fast reaches end
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete nth node
        ListNode* del = slow->next;
        slow->next = slow->next->next;
        delete del;

        return dummy->next;
    }
};