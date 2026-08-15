class LRUCache {
    struct Node {
        int key;
        int value;

        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            value = v;
            next = nullptr;
            prev = nullptr;
        }
    };

    int capacity;
    Node* temp_head;
    Node* temp_tail;

    unordered_map<int, Node*> hash;

public:

    LRUCache(int capacity) {
        this->capacity = capacity;

        temp_head = new Node(-1, -1);
        temp_tail = new Node(-1, -1);

        temp_head->next = temp_tail;
        temp_tail->prev = temp_head;
    }

    // Remove node from linked list
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Insert node immediately after head
    void pushFront(Node* node) {
        node->next = temp_head->next;
        node->prev = temp_head;

        temp_head->next->prev = node;
        temp_head->next = node;
    }

    int get(int key) {
        if (hash.find(key) == hash.end()) {
            return -1;
        }

        Node* node = hash[key];

        // Move to front because it was recently used
        remove(node);
        pushFront(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if (hash.find(key) != hash.end()) {
            Node* node = hash[key];

            node->value = value;

            // Mark as recently used
            remove(node);
            pushFront(node);

            return;
        }

        // Create new node
        Node* node = new Node(key, value);

        hash[key] = node;
        pushFront(node);

        // Capacity exceeded
        if (hash.size() > capacity) {

            // LRU node is just before tail
            Node* lru = temp_tail->prev;

            remove(lru);

            hash.erase(lru->key);

            delete lru;
        }
    }
};