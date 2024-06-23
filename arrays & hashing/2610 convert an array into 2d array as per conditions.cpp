class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        int count = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        while (count > 0) {
            vector<int> temp;
            for (const auto& ele:mp) {
                if (ele.second > 0) {
                    temp.push_back(ele.first);
                     mp[ele.first]--;
                    count--;
                }
            }
            ans.push_back(temp);
        }
            return ans;
        }
    };

//TC: O(N)
//SC: O(N)