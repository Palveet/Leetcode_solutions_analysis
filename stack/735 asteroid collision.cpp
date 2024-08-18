class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroid) {
        stack<int>s;
        for(int i=0;i<asteroid.size();i++){
            while(s.size()>0 && s.top()>0 && asteroid[i]<0){
                int diff = asteroid[i]+s.top();
                if(diff>0){
                    asteroid[i]=0;
                } else if(diff<0){
                    s.pop();
                } else {
                    asteroid[i]=0;
                    s.pop();
                }
            }
            if(asteroid[i]!=0){
                s.push(asteroid[i]);
            }
        }
        vector<int>ans;
        while(s.size()>0){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//TC:O(N)
//SC:O(N)