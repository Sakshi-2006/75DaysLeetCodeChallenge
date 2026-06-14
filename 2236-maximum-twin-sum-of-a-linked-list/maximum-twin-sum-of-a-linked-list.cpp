class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        int l = 0, r = v.size() - 1, sum = 0;
        while (l < r) {
            sum = max(sum, v[l] + v[r]);
            l++;
            r--;
        }
        return sum;
    }
};
