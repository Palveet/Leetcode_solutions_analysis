class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i=0;i<nums.size();i++){
            minHeap.push(nums[i]);
        }
        vector<int>ans;
        while(minHeap.size()>0){
            int top = minHeap.top();
            ans.push_back(top);
            minHeap.pop();
        }
        return ans;
    }
};

//TC: O(NLOGN)
//SC: O(N)