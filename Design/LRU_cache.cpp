/*
    Problem link->
        https://leetcode.com/explore/featured/card/google/65/design-4/3090/
    
    Tested on Leetcode!
*/
class Node{
    public:
        Node* prev;
        Node* next;
        int val;
        Node(int val){
            prev = NULL;
            next = NULL;
            this->val = val; 
        }
};

class LinkedList{
    public:
        Node* head,*tail;
        LinkedList(){
            head = tail = NULL;
        }
        Node* insert(int val){
            Node* node = new Node(val);
            if(!head){
                head = node;
                tail = node;
                return node;
            }
            node->next = head;
            head->prev = node;
            head = node;
            return node;
        }
        void del(Node* curr){
            if(curr == head){
                if(tail == head){
                    tail = NULL,head = NULL;
                    delete curr;
                    return;
                }
                head = head->next;
                head->prev = NULL;
                delete curr;
                return;
            }
            if(curr == tail){
                tail = tail->prev;
                tail->next = NULL;
                delete curr;
                return;
            }
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
            return;
        }
        int del_lru(){
            int key = tail->val;
            del(tail);
            return key;
        }
};

class LRUCache {
public:
    int maxSize;
    unordered_map<int,pair<int,Node*>>look;
    LinkedList* list;
    LRUCache(int capacity) {
        maxSize = capacity;
        look.clear();
        list = new LinkedList();
    }
    
    int get(int key) {
        if(!look.count(key)){
            return -1;
        }
        list->del(look[key].second);
        look[key].second = list->insert(key);
        return look[key].first;
    }
    
    void put(int key, int value) {
        if(look.count(key)){
            look[key].first = value;
            list->del(look[key].second);
            look[key].second = list->insert(key);
            return;
        }
        if((look.size() + 1) > maxSize){
            int temp = list->del_lru();
            look.erase(temp);
        }
        look[key].second = list->insert(key);
        look[key].first = value;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */