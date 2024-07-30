class OrderedStream {
public:
unordered_map<int,string>mp;
int count = 1;
    OrderedStream(int n) {
        
    }
    
    vector<string> insert(int idKey, string value) {
        mp[idKey]=value;
        vector<string>ans;
        while(mp.find(count)!=mp.end()){
            ans.push_back(mp[count]);
            count++;
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */

//TC:O(1)
//SC:O(N)