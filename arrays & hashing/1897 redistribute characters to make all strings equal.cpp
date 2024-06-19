class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int count = words.size();
        unordered_map<char,int>mp;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                mp[words[i][j]]++;
            }
        }
        for(const auto& pair:mp){
            if(pair.second%count!=0){
                return false;
                }
        }
        return true;
    }
};


//TC:O(N*M)
//SC: O(N)