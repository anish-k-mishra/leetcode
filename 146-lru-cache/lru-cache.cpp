class LRUCache {
public:
    class node {
        public:
        int key;
        int val;
        node* next = NULL;
        node* prev = NULL;

        node(int key, int val){
            this->key = key;
            this->val = val;
        }
    };
    void insertNode(node * newnode) {
        node * temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
    }
    void deleteNode(node * delnode) {
        node * delprev = delnode -> prev;
        node * delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }

    int cap;
    unordered_map<int, node*>m;
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()){
            return -1;
        }
        node* n = m[key];
        deleteNode(n);
        insertNode(n);
        return n->val;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            node* n = m[key];
            n->val = value;
            deleteNode(n);
            insertNode(n);
        }
        else{
            if(m.size() == cap){
                node* n = tail->prev;
                m.erase(n->key);
                deleteNode(n);
            }
            node* n = new node(key, value);
            m[key] = n;
            insertNode(n);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */