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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
 
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prevGroupTail = dummy;
        ListNode* curr = head;
        
        while (curr) {
 
            ListNode* checker = curr;
            int count = 0;
            while (checker && count < k) {
                checker = checker->next;
                count++;
            }
 
            if (count < k) {
                prevGroupTail->next = curr;
                break;
            }

            ListNode* prev = nullptr;
            ListNode* nextNode = nullptr;
            ListNode* groupHead = curr; 
            
            for (int i = 0; i < k; ++i) {
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            prevGroupTail->next = prev;

            prevGroupTail = groupHead;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
    }
};