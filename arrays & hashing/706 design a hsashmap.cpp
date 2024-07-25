class MyHashMap {
public:
    int hmap[1000001] = {0};
    MyHashMap() {
        memset(hmap, -1, sizeof(hmap));
    }
    
    void put(int key, int value) {
        hmap[key] = value;
    }
    
    int get(int key) {
        return hmap[key];
    }
    
    void remove(int key) {
        hmap[key] = -1;
    }
};

//TC:O(1)
//SC:O(1) because the array size is constant and no dynamic memory allocation happens