class LRUCache{
    public:
        LRUCache(int capacity) {
            this->capacity = capacity;
        }

        int get(int key) {
            unordered_map<int, int>::iterator i = cache.find(key);
            if(i != cache.end()){
                queue.erase(mapping[key]);
                queue.push_back(key);
                list<int>::iterator last = queue.end(); last --;
                mapping[key] = last;
                return i->second;
            } 
            else return -1;
        }

        void set(int key, int value) {
            unordered_map<int, int>::iterator i = cache.find(key);
            if(i == cache.end()){
                if(cache.size() < this->capacity){
                    cache[key] = value;
                    queue.push_back(key);
                    list<int>::iterator last = queue.end(); last --;
                    mapping[key] = last;
                }
                else{
                    cache.erase(queue.front());
                    mapping.erase(queue.front());
                    queue.pop_front();
                    cache[key] = value;
                    queue.push_back(key);
                    list<int>::iterator last = queue.end(); last --;
                    mapping[key] = last; 
                }
            }else{
                cache[key] = value;
                queue.erase(mapping[key]);
                queue.push_back(key);
                list<int>::iterator last = queue.end(); last --;
                mapping[key] = last;
            }
        }

        unordered_map<int, int> cache;
        unordered_map<int, list<int>::iterator> mapping;
        list<int> queue;
        int capacity;
};
