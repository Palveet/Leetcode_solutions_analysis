class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long total = 0;
        int curr = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==0){
                total +=curr+1;
                curr++;
            }else{
                curr = 0;
            }
        }
        return total;
    }
};

//TC: O(N)
//SC: O(1)