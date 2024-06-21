class Solution {
public:
    void sortColors(vector<int>& nums) {
        int countred=0;
        int countwhite=0;
        int countblue=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)countred++;
            if(nums[i]==1)countwhite++;
            if(nums[i]==2)countblue++;
        }
        for(int i=0;i<countred;i++){
            nums[i]=0;
        }
        for(int j=countred;j<countred+countwhite;j++){
            nums[j]=1;
        }
        for(int k = countred+countwhite;k<nums.size();k++){
            nums[k]=2;
        }
    }
};

//TC: O(N)
//SC: O(1)