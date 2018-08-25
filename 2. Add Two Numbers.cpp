/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool bit = (l1->val + l2->val >= 10);
        ListNode* n = new ListNode((l1->val + l2->val) % 10);
        ListNode* temp = n;
        l1 = l1->next; l2 = l2->next;
        while(l1 && l2 || bit){
            if(l1 && l2){
                int num = l1->val + l2->val + bit;
                bit = (num >= 10); num %= 10;
                temp = temp->next = new ListNode(num);
                l1 = l1->next; l2 = l2->next;
            } else {
                int num = bit;
                if(l1) {num += l1->val; l1 = l1->next;}
                if(l2) {num += l2->val; l2 = l2->next;}
                bit = (num >= 10); num %= 10;
                temp = temp->next = new ListNode(num);
            }
        }
        for(; l1; temp = temp->next = new ListNode(l1->val), l1 = l1->next);
        for(; l2; temp = temp->next = new ListNode(l2->val), l2 = l2->next);
        return n;
    }
};
