class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<vector<int>> missingRanges;
        if (n == 0) {
            missingRanges.push_back(vector<int>{lower, upper});
            return missingRanges;
        }
        if (lower < nums[0]) {
            missingRanges.push_back(vector<int>{lower, nums[0] - 1});
        }
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] <= 1) {
                continue;
            }
            missingRanges.push_back(vector<int>{nums[i] + 1, nums[i + 1] - 1});
        }
        if (upper > nums[n - 1]) {
            missingRanges.push_back(vector<int>{nums[n - 1] + 1, upper});
        }

        return missingRanges;
    }
};

//TC:O(N)
//SC:O(N)