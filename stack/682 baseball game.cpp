class Solution {
public:
    int calPoints(vector<string>& operations) {
        int score = 0;
        stack<int> s;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b);
                s.push(a);
                s.push(a + b);
            } else if (operations[i] == "D") {
                s.push(2 * s.top());
            } else if (operations[i] == "C") {
                s.pop();
            } else {
                s.push(stoi(operations[i]));
            }
        }
        while(s.size()>0){
            score+=s.top();
            s.pop();
        }
        return score;
    }
};

//TC:O(N)
//SC:O(N)