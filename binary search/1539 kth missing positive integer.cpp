class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int count = 0;
        int start = 1;
        while (count < k) {
            int low = 0;
            int high = nums.size() - 1;
            bool found = false;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (start == nums[mid]) {
                    found = true;
                    start++;
                    break;
                }
                if (start > nums[mid]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if(!found){
                count++;
                start++;
            }
        }
        return start-1;
    }
};

//TC: O(K*logN)
//sc:O(1)