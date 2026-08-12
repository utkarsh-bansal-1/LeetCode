
class LRUCache {
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> mpp;
    int cap;
    int size;

public:
    LRUCache(int capacity) {
      cap=capacity; 
      size=0;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()){
            return -1;
        }
        auto it=mpp[key];
        int value=it->second;
        l.erase(it);
        l.push_back({key , value});
        mpp[key] = prev(l.end());
        return value;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            auto it=mpp[key];
            l.erase(it);
            mpp.erase(key);
        }
        else if(cap==size){
            auto it=l.begin();
            int key=it->first;
            l.erase(l.begin());
            mpp.erase(key);
        }
        else{
            size++;
        }

        l.push_back({key , value});
        mpp[key]=prev(l.end());
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */