class DynamicArray {
public:
    vector<int> arr;
    DynamicArray(int capacity) {
        arr.reserve(capacity);
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        arr.push_back(n);
    }

    int popback() {
        int val = arr.back();
        arr.pop_back();
        return val;
    }

    void resize() {
        arr.reserve(2*arr.capacity());
    }

    int getSize() {
        return arr.size();
    }

    int getCapacity() {
        return arr.capacity();
    }
};
