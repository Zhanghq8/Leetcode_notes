#include <iostream>
#include <string>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        max_size = capacity;
    }
    
    int get(int key) {
        auto itr = umap.find(key);
        if (itr != umap.end()) {
            cache.splice(cache.begin(), cache, itr->second);
            return itr->second->second;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto itr = umap.find(key);
        if (itr != umap.end()) {
            cache.erase(itr->second);
        }
        cache.push_front(make_pair(key, value));
        umap[key] = cache.begin();
        if (umap.size() > max_size) {
            int k = cache.back().first;
            cache.pop_back();
            umap.erase(k);
        }

    }
private:
    unordered_map<int, list<pair<int,int>>::iterator> umap;
    list<pair<int,int>> cache;
    int max_size;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */