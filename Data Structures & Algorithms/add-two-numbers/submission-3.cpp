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
        int sum;
        int carry=0;
        int ogSum=0;
        ListNode dummy(0);
        ListNode* temp = &dummy;
        while (l1 && l2){
            int element1 = l1->val;
            int element2 = l2->val;
            sum = element1 + element2 + carry;
            ogSum = sum % 10;
            carry = sum / 10;
            temp->next = new ListNode(ogSum);
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *check = (l1 != nullptr) ? l1 : l2;
        while (check){
            sum = check->val + carry;
            ogSum = sum % 10;
            carry = sum / 10;
            temp->next = new ListNode(ogSum);
            temp = temp->next;
            check = check ->next;
        }
        if (carry)
            temp->next = new ListNode(carry);
        return dummy.next;
    }
};
