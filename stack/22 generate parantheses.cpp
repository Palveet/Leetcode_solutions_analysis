class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        backtrack(n,0,0,"",result);
        return result;
    }
private:
    void backtrack(int n,int open,int close,string s,vector<string>&result){
        if(open==n && close==n){
            result.push_back(s);
            return;
        }
        if(open<n){
            backtrack(n,open+1,close,s+'(',result);
        }
        if(open>close){
            backtrack(n,open,close+1,s+')',result);
        }
    }
};

//TC: O(2^n)
//SC: O(n)