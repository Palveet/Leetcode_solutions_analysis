class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> left, right, count;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if (left.find(x) == left.end()) {
                left[x] = i;
            }
            right[x] = i;
            count[x]++;
        }

        int ans = nums.size();
        int degree = 0;

        for (const auto& kv : count) {
            degree = max(degree, kv.second);
        }

        for (const auto& kv : count) {
            if (kv.second == degree) {
                ans = min(ans, right[kv.first] - left[kv.first] + 1);
            }
        }

        return ans;

    }
};

//TC:O(N)
//SC:O(N)