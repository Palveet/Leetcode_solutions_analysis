class Solution {
public:
    int partitionString(string s) {
        int ans=0;
        int i = 0;
        int j = 0;
        unordered_map<char,int>mp;
        while(j<s.size()){
            if(mp.find(s[j])!=mp.end()){
                ans++;
                i = j;
                mp.clear();
            } else {
                mp[s[j]]++;
                j++;
            }
        }
        if(mp.size()>0){
            ans++;
        }
        return ans;
    }
};

//TC: O(N);
//SC: O(1)