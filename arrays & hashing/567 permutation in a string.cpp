class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if(m>n)return false;
        vector<int>count(26);
        for(int i=0;i<m;i++){
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        if(isPermutation(count)){
            return true;
        }
        for(int i=m;i<n;i++){
            count[s2[i]-'a']--;
            count[s2[i-m]-'a']++;
            if(isPermutation(count)){
                return true;
            }
        }
        return false;
    }
private:
    bool isPermutation(vector<int>& count){
        for(int i=0;i<26;i++){
            if(count[i]!=0)return false;
        }
        return true;
    }
};


//TC: O(N) because the isPermutation function has constant TC of O(26)
//SC: O(1) because count will be always of size 26 and does not change according to the size of s1 or s2