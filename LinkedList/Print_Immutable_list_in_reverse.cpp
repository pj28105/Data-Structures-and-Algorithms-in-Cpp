/*  
    Problem link->
        https://leetcode.com/problems/print-immutable-linked-list-in-reverse/
    
    Time-> O(N) Space-> O(sqrt(N))

    Steps->
        1) len <- Find length of linked list
        2) Assume your list is divided in blocks of size sqrt(len)
        3) Store every starting node of every block this will take o(sqrt(n)) space
        4) Print every block of lists using stack in reverse.
        5) stack will also take o(sqrt(n)) space at max.
*/

/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */
class Solution {
public:
    void printlist(ImmutableListNode* start,ImmutableListNode* end){
        stack<ImmutableListNode*>st;
        while(start != end){
            st.push(start);
            start = start->getNext();
        }
        while(!st.empty()){
            st.top()->printValue();
            st.pop();
        }
        return;
    }
    void printLinkedListInReverse(ImmutableListNode* head) {
        int len = 0;
        ImmutableListNode* curr = head;
        while(curr){
            len++;
            curr = curr->getNext();
        }
        int blk_siz = ceil(sqrt(len)),cnt = 0;
        vector<ImmutableListNode*> startNodes;
        curr = head;
        while(curr){
            if(cnt % blk_siz == 0){
                startNodes.push_back(curr);
            }
            cnt++;
            curr = curr->getNext();
        }
        ImmutableListNode* end = NULL;
        for(int i = startNodes.size() - 1; i >= 0; i--){
            printlist(startNodes[i],end);
            end = startNodes[i];
        }
        return;
    }
};