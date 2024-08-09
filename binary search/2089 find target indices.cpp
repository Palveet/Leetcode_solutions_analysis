class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int pivot = -1;
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid =low+ (high-low)/2 ;
            if(target==nums[mid])pivot = mid;
            if(target>nums[mid]){
                low = mid+1;
            }
            else{
                high=mid-1;
            }
        }
        if(pivot==-1)return ans;
        int temp = pivot;
        while(temp>-1){
            if(nums[temp]==target){
                ans.push_back(temp);
                temp--;
            } else {
                break;
            }
        }
        sort(ans.begin(),ans.end());
        temp = pivot+1;
        while(temp<nums.size()){
            if(nums[temp]==target){
                ans.push_back(temp);
                temp++;
            } else {
                break;
            }
        }
        return ans;
    }
};

//TC:O(Nlogn)
//sc:o(n)