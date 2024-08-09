class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        unordered_set<int> taken;
        
        for (int index = 0; index < nums.size(); ++index) {
            if (taken.count(nums[index])) {
                continue;
            }
            
            if (minHeap.size() == 3) {
                if (minHeap.top() < nums[index]) {
                    taken.erase(minHeap.top());
                    minHeap.pop();
                    
                    minHeap.push(nums[index]);
                    taken.insert(nums[index]);
                }
            } 
            else {
                minHeap.push(nums[index]);
                taken.insert(nums[index]);
            }
        }
        
        if (minHeap.size() == 1) {
            return minHeap.top();
        }
        else if (minHeap.size() == 2) {
            int firstNum = minHeap.top();
            minHeap.pop();
            return max(firstNum, minHeap.top());
        }
        
        return minHeap.top();
    }
};

//TC:O(N)
//SC:O(N)