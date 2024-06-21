class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negCount = 0;
        int posCount = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)return 0;
            if(nums[i]>0) posCount++;
            if(nums[i]<0) negCount++;
        }
        if(negCount%2==0)return 1;
        return -1;
    }
};

//TC: O(N)
//SC: O(1)