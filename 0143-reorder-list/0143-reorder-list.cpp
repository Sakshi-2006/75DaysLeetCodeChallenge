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
// Input:
// 1 → 2 → 3 → 4 → 5
//head      ↑ mid
// Step 1 (split):
// 1 → 2 → 3     4 → 5

// Step 2 (reverse):
// 1 → 2 → 3     5 → 4

// Step 3 (merge):
// 1 → 5 → 2 → 4 → 3

// Pattern:
// First element
// Last element
// Second element
// Second last
// and so on...

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = NULL;

        ListNode* prev = NULL;
        while (second) {
            ListNode* nextNode = second->next;
            second->next = prev;
            prev = second;
            second = nextNode;
        }
        ListNode* first = head;
        second = prev;

        while (second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};