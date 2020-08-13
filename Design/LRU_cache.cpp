/*
    Problem link->
        https://leetcode.com/explore/featured/card/google/65/design-4/3090/
    
    Tested on Leetcode!
*/
class LinkedList{
    public:
        LinkedList *prev,*next;
        int key,value;
        static LinkedList* head,*tail;
        LinkedList(int key = -1,int value = -1){
            this->prev = NULL;
            this->next = NULL;
            this->key = key;
            this->value = value;
        }
        void insert(LinkedList* node){
            if(head == NULL){
                head = node;
                tail = node;
                return;
            }
            node->next = head;
            head->prev = node;
            head = node;
            return;
        }
        void del(LinkedList* node){
            if(tail == node){
                del_lru();
                return;
            }
            if(head == node){
                head = head->next;
                head->prev = NULL;
                delete node;
                return;
            }
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
            return;
        }    
        int del_lru(){
            if(head == tail){
                int key = head->key;
                delete head;
                head = NULL;
                tail = NULL;
                return key;
            }
            int key = tail->key;
            LinkedList* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
            return key;
        } 
};

LinkedList* LinkedList::head = NULL;
LinkedList* LinkedList::tail = NULL;

class LRUCache {
public:
    int size = 0;
    unordered_map<int,LinkedList*>ma;
    LinkedList control;
    LRUCache(int capacity) {
           size = capacity;
           ma.clear();
           LinkedList::head = NULL;
           LinkedList::tail = NULL;
    }
    
    int get(int key) {
        if(ma.find(key) == ma.end()){
            return -1;
        }
        int value = ma[key]->value;
        control.del(ma[key]);
        LinkedList* node = new LinkedList(key,value);
        ma[key] = node;
        control.insert(node);
        return value;
    }
    
    void put(int key, int value) {
        if(ma.find(key) == ma.end()){
            if(size < (ma.size() + 1)){
                int x = control.del_lru();
                ma.erase(x);
            }
            LinkedList* node = new LinkedList(key,value);
            control.insert(node);
            ma[key] = node;
            return;
        }
        control.del(ma[key]);
        LinkedList *node = new LinkedList(key,value);
        control.insert(node);
        ma[key] = node;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */