class Solution {
public:
    string makeGood(string s) {
        stack<char>sk;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(sk.size()>0 && (sk.top()-32 ==s[i] ||sk.top()+32==s[i])){
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