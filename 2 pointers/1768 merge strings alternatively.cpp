class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        string ans = "";
        while (i < word1.size() && i < word2.size()) {
            char a= word1[i];
            char b= word2[i];
            ans+= a;
            ans+=b;
            i++;
        }
        if (i < word1.size()) {
            while (i < word1.size()) {
                char a= word1[i];
                ans += a;
                i++;
            }
        }
        if (i < word2.size()) {
            while (i < word2.size()) {
                char b= word2[i];
                ans += b;
                i++;
            }
        }
        return ans;
    }
};

//TC:O(N)
//SC:O(N)