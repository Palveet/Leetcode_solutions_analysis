class Solution {
public:
    string removeStars(string s) {
        stack<char>sk;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(sk.size()>0 && s[i]=='*'){
                sk.pop();
            } else {
                sk.push(s[i]);
            }
        }
        while(sk.size()>0){
            ans+=sk.top();
            sk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//TC:O(N)
//SC:O(N)