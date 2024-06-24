class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans =INT_MAX;
        int low = 0;
        int high = k;
        while(high-1<nums.size()){
            ans = min(ans,nums[high-1]-nums[low]);
            low++;
            high++;
        }
        return ans;
    }
};

//TC:O(NlogN)
//SC:O(1)