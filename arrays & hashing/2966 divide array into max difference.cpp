class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(nums.size()%3!=0)return vector<vector<int>>();
        vector<vector<int>> ans(nums.size() / 3, vector<int>(3));
        int j = 0;
        int count = 0;
        int i = 0;
        while(i<=nums.size()-3){
            ans[j][0]=nums[i];
            ans[j][1]=nums[i+1];
            ans[j][2]=nums[i+2];
            j++;
            i = i+3;
        }
        
        for(int i=0;i<ans.size();i++){
            if(abs(ans[i][1]-ans[i][0])>k)return vector<vector<int>>();
            if(abs(ans[i][1]-ans[i][2])>k)return vector<vector<int>>();
            if(abs(ans[i][2]-ans[i][0])>k)return vector<vector<int>>();
        }
        return ans;
    }
};


//TC: O(N)
//SC: O(N)