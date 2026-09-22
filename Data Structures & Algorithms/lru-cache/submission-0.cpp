#include <unordered_map>
using namespace std;

class LRUCache {
public:
    struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    // helper: remove node from list
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // helper: insert node right after head
    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        remove(node);
        insert(node); // move to front (MRU)
        return node->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            remove(node);
            insert(node);
        } else {
            if (mp.size() == capacity) {
                // evict LRU (node before tail)
                Node* lru = tail->prev;
                remove(lru);
                mp.erase(lru->key);
                delete lru;
            }
            Node* node = new Node(key, value);
            mp[key] = node;
            insert(node);
        }
    }
};
