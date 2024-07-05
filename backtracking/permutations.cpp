class Solution {
public:
    void perm(vector<int>& nums, int start, vector<vector<int>>& fans) {
        if (start == nums.size()-1) {
            fans.push_back(nums);
            return;
        }
        for(int i=start;i<nums.size();i++){
            swap(nums[start],nums[i]);
            perm(nums,start+1,fans);
            swap(nums[start],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> fans;
        perm(nums, 0, fans);
        return fans;
    }
};

//TC:O(N!)
//SC:O(N)