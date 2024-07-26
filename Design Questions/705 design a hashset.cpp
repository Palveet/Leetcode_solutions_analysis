class MyHashSet {
public:
    int hmap[1000001] = {0};
    MyHashSet() {
    memset(hmap, -1, sizeof(hmap));
    }
    
    void add(int key) {
        hmap[key]=1;
    }
    
    void remove(int key) {
        hmap[key]=-1;
    }
    
    bool contains(int key) {
        if(hmap[key]!=-1)return true;
        return false;
    }
};

//TC: O(1)
//SC: O(1)

