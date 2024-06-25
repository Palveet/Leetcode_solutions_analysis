class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>ans;
        int i =0;
        while(i<nums.size()){
            if(nums[i]%2==0){
                ans.push_back(nums[i]);
                nums.erase(nums.begin()+i);
            } else {
                i++;
            }
        }
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};

//TC:O(N)
//SC:O(N)