class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string ans = "";
        for(int i=0;i<words.size();i++){
            ans = words[i];
            reverse(words[i].begin(),words[i].end());
            if(words[i]==ans){
                return ans;
            }
        }
        ans = "";
        return ans;
    }
};

//TC: O(N)
//SC: O(1)