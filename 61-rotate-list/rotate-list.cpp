class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == NULL) return head;
        int total = 0;
        ListNode* temp = head;

        while(temp != NULL) {
            temp = temp -> next;
            total++;
        }

        k = k % total;
        if(k == 0) return head;
        int dest = total - k  - 1;

        temp = head;
        while(dest--) temp = temp -> next;

        ListNode* start = temp -> next;
        temp -> next = NULL;

        temp = start;
        while(temp != NULL && temp -> next != NULL) temp = temp -> next;
        temp -> next = head;

        return start;
    }
};