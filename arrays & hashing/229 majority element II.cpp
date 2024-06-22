class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int count = nums.size()/3;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(const auto& element:mp){
            if(element.second>count){
                ans.push_back(element.first);
            }
        }
        return ans;
    }
};

//TC: O(1)
//SC: O(N)