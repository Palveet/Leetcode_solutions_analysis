class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        long long sum = 0;
        long long maxInt = nums[0];
        vector<long long> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxInt){
                maxInt=nums[i];
            }
            sum+=maxInt+nums[i];
            ans.push_back(sum);
        }
        return ans;
    }
};

//TC:O(N)
//SC:O(N)