class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(int i=0;i<tokens.size();i++){
            string token = tokens[i];
            if(token.size()>1 || isdigit(token[0])){
                s.push(stoi(token));
                continue;
            }
            int num2 = s.top();
            s.pop();
            int num1 = s.top();
            s.pop();
            
            int result = 0;
            if (token == "+") {
                result = num1 + num2;
            } else if (token == "-") {
                result = num1 - num2;
            } else if (token == "*") {
                result = num1 * num2;
            } else {
                result = num1 / num2;
            }
            s.push(result);
        }
        return s.top();
    }
};

//TC: O(N)
//SC: O(N)