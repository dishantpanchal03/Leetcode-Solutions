class MyHashSet {
private:
    static const int BUCKETS = 1009;
    vector<vector<int>> table;

    int hash(int key) {
        return key % BUCKETS;
    }

public:
    MyHashSet() {
        table.resize(BUCKETS);
    }

    void add(int key) {
        int index = hash(key);

        // Don't add duplicate
        for (int x : table[index]) {
            if (x == key)
                return;
        }

        table[index].push_back(key);
    }

    void remove(int key) {
        int index = hash(key);

        for (auto it = table[index].begin();
             it != table[index].end();
             ++it) {

            if (*it == key) {
                table[index].erase(it);
                return;
            }
        }
    }

    bool contains(int key) {
        int index = hash(key);

        for (int x : table[index]) {
            if (x == key)
                return true;
        }

        return false;
    }
};


/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */