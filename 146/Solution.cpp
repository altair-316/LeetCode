#include<bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    unordered_map<int,int> C;
    int c=0;
    queue<int> q;
public:
    LRUCache(int capacity) {
        c=capacity;    
    }
    
    int get(int key) {
        if(C.find(key)!=C.end()){
            
            q.

            return(C.find(key)->second);
        }
        else
            return(-1);

    }
    
    void put(int key, int value) {

        if(C.size()<c){
            C.insert(pair<int,int>(key,value));
            q.push(key);
        }
        else{
            int kt=q.front();
            q.pop();
            C.erase(kt);
            C.insert(pair<int,int>(key,value));
            q.push(key);
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 
 Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 
 
 */