/*
    Problem link->
        https://leetcode.com/problems/linked-list-random-node/
    
    This problem is based on Reservoir Sampling in which we have to choose
    a node randomly without knowing the size of the linkedlist. 

    Refer Leetcode editorial in case any issues!
    Tested on Leetcode!
*/
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* list;
    Solution(ListNode* head) {
        list = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* curr = list;
        int val = curr->val;
        curr = curr->next;
        for(int i = 2; curr != NULL ;i++,curr = curr->next){
            int num = (rand() % i) + 1;
            if(num == 1){
                val = curr->val;
            }
        }
        return val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */