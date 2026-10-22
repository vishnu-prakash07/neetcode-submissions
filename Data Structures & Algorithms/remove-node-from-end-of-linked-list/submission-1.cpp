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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
            return NULL;
        int sze = 0;
        ListNode* temp = head;
        sze++;
        while (temp->next != NULL){
            temp = temp->next;
            sze++;
        }
        cout << sze << endl;
        cout << sze - n << endl;
        if (sze == 1)
            return NULL;
        int val = sze - n;
        if (val == 0)
            return head->next;
        temp = head;
        for (int i=1;i<val;i++){
            temp = temp->next;
        }
        if (temp->next->next == NULL)
            temp->next = NULL;
        else
            temp->next = temp->next->next;



        return head;
    }
};
