/**
 * Problem link-> https://leetcode.com/problems/reverse-nodes-in-k-group/
 * Tested on Leetcode
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head){
        if(!head or !head->next){
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head or k == 1 or !head->next){
            return head;
        }
        ListNode* Dummy = new ListNode(-1);
        Dummy->next = head;
        ListNode* end = Dummy,*curr = head;
        int cnt = 0;
        while(curr){
            cnt++;
            if(cnt == k){
                ListNode* temp = curr->next;
                curr->next = NULL;
                ListNode* currTail = end->next;
                ListNode* currHead = reverseList(currTail);
                currTail->next = temp;
                end->next = currHead;
                end = currTail;
                curr = temp;
                cnt = 0;
            }else
                curr = curr->next;
        }
        return Dummy->next;
    }
};