class Solution {
public:
void helper(vector<int>& cands, int target, int i,vector<int>& curr,vector<vector<int>>& res) {
        if (i >= cands.size() || target < 0)
            return;
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        curr.push_back(cands[i]);
        helper(cands, target - cands[i], i, curr, res);
        curr.pop_back();
        helper(cands, target, i + 1, curr, res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> res;
        helper(candidates, target, 0, curr, res);
        return res;
    }
};

//TC: O(2^target)
//SC: O(target)