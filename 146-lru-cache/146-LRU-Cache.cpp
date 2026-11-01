class LRUCache {
private:
    int cap;
    list<pair<int, int>> cacheList; 
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap; 

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        return cacheMap[key]->second;
    }
    
    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            cacheMap[key]->second = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            return;
        }
        
        if (cacheList.size() == cap) {
            auto last = cacheList.back();
            cacheMap.erase(last.first);
            cacheList.pop_back();
        }
        cacheList.push_front({key, value});
        cacheMap[key] = cacheList.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */