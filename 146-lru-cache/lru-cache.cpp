#include <unordered_map>
using namespace std;

// Doubly Linked List Node
struct Node {
    int key, value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;  // Map to store key to node mapping
    Node* head;  // Dummy head of the doubly linked list
    Node* tail;  // Dummy tail of the doubly linked list

    // Helper function to remove a node from the doubly linked list
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Helper function to add a node to the front of the doubly linked list
    void addNodeToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);  // Create a dummy head
        tail = new Node(0, 0);  // Create a dummy tail
        head->next = tail;      // Connect head to tail
        tail->prev = head;      // Connect tail to head
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;  // Key not found
        }
        
        // Move the accessed node to the front
        Node* node = cache[key];
        removeNode(node);
        addNodeToFront(node);
        
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key exists, update the value and move it to the front
            Node* node = cache[key];
            node->value = value;
            removeNode(node);
            addNodeToFront(node);
        } else {
            // Key doesn't exist, insert a new node
            if (cache.size() == capacity) {
                // Cache is full, remove the least recently used node
                Node* tailPrev = tail->prev;
                removeNode(tailPrev);
                cache.erase(tailPrev->key);
                delete tailPrev;  // Delete the node from memory
            }

            Node* newNode = new Node(key, value);
            addNodeToFront(newNode);
            cache[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key, value);
 */
