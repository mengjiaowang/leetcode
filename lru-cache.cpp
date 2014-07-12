class LRUCache{
    public:
        LRUCache(int capacity) {
            this->capacity = capacity;
            this->count = 0;
        }

        int get(int key) {
            unordered_map<int, int>::iterator i = mapping.find(key);
            if(i != mapping.end()) return i->second;
            else return -1;
        }

        void set(int key, int value) {
            if(keyList.size() < capacity){
                keyList.push_back(key);
                mapping[key] = value;
            }else{
                int oldKey = keyList.front();
                keyList.pop_front();
                mapping.erase(oldKey);
                keyList.push_back(key);
                mapping[key] = value;
            }
        }

        unordered_map<int, int> mapping;
        list<int> keyList;
        int capacity;
        int count;
};
