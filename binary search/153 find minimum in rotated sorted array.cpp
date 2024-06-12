class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = nums[0];
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            if(nums[left]<nums[right]){
                if(ans>nums[left]){
                    ans = nums[left];
                }
            }
            int middle = (left+right)/2;
            if(ans>nums[middle]){
                ans = nums[middle];
            }
            if(nums[middle]>=nums[left]){
                left = middle + 1;
            }
            else{
                right = middle - 1;
            }
        }
        return ans;
    }
};


//TC: O(logn)
//SC: O(1)