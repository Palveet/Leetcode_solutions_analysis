class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isDec = true;
        bool isInc = true;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                isInc = false;
            } 
            if(nums[i-1]<nums[i]){
                isDec = false;
            }
            if(!isInc && !isDec){
                return false;
            }
        }
        return isInc || isDec;
    }
};

//TC: O(N)
//SC: O(1)