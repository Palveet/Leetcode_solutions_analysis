class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int count = 0;
        while (j < nums.size()) {
            if (nums[i] == nums[j]) {
                j++;
                count++;
            } else {
                if (count > 2) {
                    nums.erase(nums.begin() + i + 2, nums.begin() + i + count);
                    i = i + 2;
                    j = i;
                    count = 0;
                } else {
                    i = j;
                    count = 0;
                }
            }
            if (j == nums.size()  && count > 2) {
                nums.erase(nums.begin() + i + 2, nums.begin() + i + count);
                i = i + 2;
                j = i;
                count = 0;
            }
        }
        return nums.size();
    }
};

//TC:O(N)
//SC:O(1)