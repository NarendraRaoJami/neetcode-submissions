struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class LinkedList {
public:
    ListNode* root;
    int size;

    LinkedList() {
        root = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }

        ListNode* temp = root;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        return temp->val;
    }

    void insertHead(int val) {
        ListNode* newHead = new ListNode(val);
        newHead->next = root;
        root = newHead;
        size++;
    }

    void insertTail(int val) {
        ListNode* newTail = new ListNode(val);

        if (root == nullptr) {
            root = newTail;
            size++;
            return;
        }

        ListNode* temp = root;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newTail;
        size++;
    }

    bool remove(int index) {
        if (index < 0 || index >= size) {
            return false;
        }

        if (index == 0) {
            ListNode* temp = root;
            root = root->next;
            delete temp;
            size--;
            return true;
        }

        ListNode* prev = root;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->next;
        }

        ListNode* temp = prev->next;
        prev->next = temp->next;
        delete temp;

        size--;
        return true;
    }

    vector<int> getValues() {
        vector<int> result;

        ListNode* temp = root;
        while (temp != nullptr) {
            result.push_back(temp->val);
            temp = temp->next;
        }

        return result;
    }
};