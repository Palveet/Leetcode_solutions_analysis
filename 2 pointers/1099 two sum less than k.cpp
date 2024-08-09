class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i =0;
        int j = nums.size()-1;
        int sum =-1;
        while(i<j){
            int temp = nums[i]+nums[j];
            if(temp>=k){
                j--;
            } else if(temp<k){
                sum = max(sum, temp);
                i++;
            }
        }
        return sum; 
    }
};

//TC:O(Nlogn)
//SC:O(1)