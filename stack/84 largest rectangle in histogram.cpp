//Solution 1

//Calculating NSR & NSR
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>left;
        vector<int>right;
        stack<pair<int,int>>s;
        int ans = 0;
        for(int i = heights.size()-1;i>=0;i--){
            if(s.size()==0){
                right.push_back(heights.size());
            }
            else if(s.size()>0 && s.top().first<heights[i]){
                right.push_back(s.top().second);
            }
            else if(s.size()>0 && s.top().first>=heights[i]){
                while(s.size()>0 && s.top().first>=heights[i]){
                    s.pop();
                }
                if(s.size()==0){
                    right.push_back(heights.size());
                } else{
                right.push_back(s.top().second);
                }
            }
            s.push({heights[i],i});
        }
        reverse(right.begin(),right.end());
        if(s.size()>0){
            while(s.size()>0){
                s.pop();
            }
        }
        for(int i = 0;i<heights.size();i++){
            if(s.size()==0){
                left.push_back(-1);
            }
            else if(s.size()>0 && s.top().first<heights[i]){
                left.push_back(s.top().second);
            }
            else if(s.size()>0 && s.top().first>=heights[i]){
                while(s.size()>0 && s.top().first>=heights[i]){
                    s.pop();
                }
                if(s.size()==0){
                    left.push_back(-1);
                } else{
                left.push_back(s.top().second);
                }
            }
            s.push({heights[i],i});
        }
        for(int i=0;i<left.size();i++){
            int w = right[i]-left[i]-1;
            int h = heights[i];
            int a = w*h;
            ans = max(ans,a);
        }
        return ans;
    }
};

//TC: O(N)
//SC: O(N)