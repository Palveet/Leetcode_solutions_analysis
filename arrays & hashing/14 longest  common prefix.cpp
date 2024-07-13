class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int i=0;i<strs[0].size();i++){
            char common = strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(common!=strs[j][i]){
                    return ans;
                }
            }
            ans+=strs[0][i];
        }
        return ans;
    }
};

//TC:O(N*M)
//SC:O(1)