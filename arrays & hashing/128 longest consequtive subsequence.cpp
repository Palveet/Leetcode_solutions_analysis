class Solution {
public:
     int longestConsecutive(vector<int>& nums) {
        if(nums.size()<1)return 0;
        unordered_set<int>s(nums.begin(),nums.end());
        int ans=1;
        for(auto &n:s){
            if(!s.count(n-1)){
                int length = 1;
                while(s.count(n+length)){
                    length++;
                }
                ans=max(length,ans);
            }
        }
        return ans;
    }
};

/*
### Time Complexity

The time complexity of the `longestConsecutive` function can be analyzed as follows:

1. **Building the unordered set**: Constructing an `unordered_set` from the input vector `nums` takes \(O(n)\) time, where \(n\) is the number of elements in `nums`. This is because each element is inserted into the set, and each insertion operation on average takes constant time, \(O(1)\).

2. **Iterating through the set**: The outer loop iterates over each element in the set, which takes \(O(n)\) time because there are \(n\) elements.

3. **Checking for the start of a sequence**: For each element, we check if it is the start of a sequence by looking for `n-1` in the set. This check is \(O(1)\) due to the average constant time complexity of set operations.

4. **Finding the length of the sequence**: If an element is the start of a sequence (i.e., `n-1` is not in the set), we then enter the while loop to find the length of the sequence. In the worst case, this while loop will run for the entire length of the sequence. Across all elements, each element is considered part of the sequence exactly once, resulting in a total time complexity of \(O(n)\) for this step.

Combining these steps, the overall time complexity is:

\[ O(n) + O(n) + O(n) = O(n) \]

### Space Complexity

The space complexity of the function is dominated by the space used by the `unordered_set`:

1. **Space for the unordered set**: The `unordered_set` stores each element of the input vector `nums`, so it requires \(O(n)\) space.

Other variables such as `ans` and `length` use \(O(1)\) space.

Thus, the overall space complexity is:

\[ O(n) \]

### Summary

- **Time Complexity**: \(O(n)\)
- **Space Complexity**: \(O(n)\)
*/