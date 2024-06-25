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


class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = 0;
        int j = 0;
        while (i < s.size()) {
            if (s[i] == '#') {
                if (i == 0) {
                    s.erase(s.begin() + i);
                } else {
                    s.erase(s.begin() + i - 1, s.begin() + i + 1);
                    i = i - 1;
                }
            } else
                i++;
        }
        while (j < t.size()) {
            if (t[j] == '#') {
                if (j == 0) {
                    t.erase(t.begin() + j);
                } else {
                    t.erase(t.begin() + j - 1, t.begin() + j + 1);
                    j = j - 1;
                }

            } else
                j++;
        }
        return s == t;
    }
};


//TC:O(N)
//SC:O(1)