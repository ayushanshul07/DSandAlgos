class LRUCache {
private:
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    list<pair<int,int>> dll;
    int m_capacity;
public:
    LRUCache(int capacity): m_capacity(capacity) {
        
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        auto it = mp[key];
        dll.splice(dll.begin(), dll, it);
        return it->second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            auto it = mp[key];
            it->second = value;
            dll.splice(dll.begin(), dll, it);
        }
        else{
            if(mp.size() == m_capacity){
                int k = dll.back().first; dll.pop_back();
                mp.erase(k);
            }
            
            dll.emplace_front(key,value);
            mp[key] = dll.begin();
        }
    }
};
