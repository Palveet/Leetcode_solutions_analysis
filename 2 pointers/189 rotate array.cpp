class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k>nums.size()){
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+(k%nums.size()));
        reverse(nums.begin()+(k%nums.size()),nums.end());
        } else {
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        }
    }
};

//TC: O(N)
//SC: O(1)