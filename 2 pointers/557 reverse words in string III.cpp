class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int j = 0;
        while(j<s.size()){
            if(s[j]==32 || j==s.size()-1){
                if(j==s.size()-1){
                reverse(s.begin()+i,s.begin()+j+1);
                } else {
                reverse(s.begin()+i,s.begin()+j);
                }
                i = j+1;
                j++;
            } else {
                j++;
            }
        }
        return s;
    }
};

//TC:O(N)
//SC:O(1)