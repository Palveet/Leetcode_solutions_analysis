class Solution {
public:
    int countElements(vector<int>& arr) {
        int ans = 0;
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(const auto& ele:mp){
            if(mp.find(ele.first+1)!=mp.end()){
                ans+=ele.second;
            }
        }
        return ans;
    }
};

//TC:O(N)
//SC:O(N)