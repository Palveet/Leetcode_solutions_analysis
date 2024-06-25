class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1;
        stack<char>s2;
        string one="";
        string two="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='#' && s1.size()>0){
                s1.pop(); 
            }
            if(s[i]!='#'){
                s1.push(s[i]);
            }
        }
        while(s1.size()>0){
            char a = s1.top();
            one+=a;
            s1.pop();
        }
        for(int i=0;i<t.size();i++){
            if(t[i]=='#' && s2.size()>0){
                s2.pop(); 
            } 
            if(t[i]!='#'){
                s2.push(t[i]);
            }
        }
        while(s2.size()>0){
            char a = s2.top();
            two+=a;
            s2.pop();
        }
        return one==two;
    }
};

//TC:O(N)
//SC:O(N)