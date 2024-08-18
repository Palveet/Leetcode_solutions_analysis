class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans =0;
        int i =0;
        int j =0;
        int temp = 0;
        while(j<s.size()-1){
            if(s[j]+1 == s[j+1]){
                temp++;
                j++;
            } else {
                ans = max(ans,temp+1);
                temp =0;
                i=j+1;
                j = i;
            }
        }
        ans = max(ans,temp+1);
        return ans;
    }
};

//TC: O(N)
//SC: O(1)