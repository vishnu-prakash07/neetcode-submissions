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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count = 1;
        if (head == NULL || left == right)
            return head;
        ListNode* first = head;
        ListNode* preFirst = NULL;
        while (first != NULL && count < left){
            preFirst = first;
            first = first->next;
            count++;
        }
        if (first == NULL)
            return head;
        ListNode* second = first;
        ListNode* nextSec;
        while (second != NULL && count < right){
            second = second->next;
            count++;
        }
        if (second == NULL)
            return head;
        nextSec = second->next;
        ListNode* prev = nextSec;
        ListNode* curr = first;
        while (curr != nextSec){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        if (preFirst != NULL)
            preFirst->next = second;
        else
            head = second;
        
        return head;
    }
};