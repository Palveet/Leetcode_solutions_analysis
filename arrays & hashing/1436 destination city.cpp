class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string>mp;
        for(int i=0;i<paths.size();i++){
            mp[paths[i][0]]=paths[i][1];
        }
        for(const auto& pair:mp){
            if(mp.find(pair.second)==mp.end()){
                return pair.second;
            }
        }
        return "";
    }
};

//TC: O(N)
//SC: O(N)