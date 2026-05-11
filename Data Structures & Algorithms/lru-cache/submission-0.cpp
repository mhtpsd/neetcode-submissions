class LRUCache {
public:

    class Node {
    public:
        int key;
        int value;

        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;

    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {

        this->capacity = capacity;

        // Dummy nodes
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    // Remove node from list
    void remove(Node* node) {

        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Insert node right after head
    void insert(Node* node) {

        Node* nextNode = head->next;

        head->next = node;
        node->prev = head;

        node->next = nextNode;
        nextNode->prev = node;
    }

    int get(int key) {

        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        // Move to front
        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            Node* existing = mp[key];

            remove(existing);

            mp.erase(key);
        }

        Node* node = new Node(key, value);

        mp[key] = node;

        insert(node);

        // Remove LRU
        if (mp.size() > capacity) {

            Node* lru = tail->prev;

            remove(lru);

            mp.erase(lru->key);

            delete lru;
        }
    }
};