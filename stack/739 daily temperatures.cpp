class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>answer;
        stack<pair<int,int>>s;
        for(int i = temperatures.size()-1;i>=0;i--){
            if(s.size()==0){
                answer.push_back(0);
            }
            if(s.size()>0 && s.top().first>temperatures[i]){
                answer.push_back(s.top().second-i);
            }
            if(s.size()>0 && s.top().first<=temperatures[i]){
                while(s.size()>0 && s.top().first<=temperatures[i]){
                    s.pop();
                }
                if(s.size()==0){
                    answer.push_back(0);
                }
                else{
                    answer.push_back(s.top().second-i);
                }
            }
            s.push({temperatures[i],i});
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};

//TC: O(N)
//SC: O(N)