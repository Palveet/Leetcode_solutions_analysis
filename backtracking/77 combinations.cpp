class Solution {
public:
    void backtrack(vector<vector<int>>& ans, int start,int k,int n,vector<int>& comb){
        if(comb.size()==k){
            ans.push_back(comb);
            return;
        }
        for(int i=start;i<=n;i++){
            comb.push_back(i);
            backtrack(ans,i+1,k,n,comb);
            comb.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>comb;
        backtrack(ans,1,k,n,comb);
        return ans;
    }
};

/*
Let's analyze the time and space complexity of the given code.

### Code Analysis

The code generates all combinations of `k` numbers out of `n`. It uses backtracking to explore all possible combinations.

### Time Complexity

1. **Combinatorial Explosion:**
   - The number of combinations of `k` elements from `n` elements is given by \( C(n, k) = \frac{n!}{k! \cdot (n-k)!} \).
   - The `backtrack` function generates all possible combinations. For each valid combination (of size `k`), the algorithm spends `O(k)` time to copy it into the `ans` vector.
   - Therefore, the total time complexity is \( O(k \cdot C(n, k)) \).

2. **Loop Iterations:**
   - The loop runs `n` times at the first level, `n-1` times at the second level, and so on, leading to a factorial behavior in the recursive calls.
   - However, the dominant factor is the number of combinations \( C(n, k) \) as described above.

Hence, the overall time complexity is \( O(k \cdot C(n, k)) \).

### Space Complexity

1. **Auxiliary Space:**
   - The recursion depth is `k`, so the call stack uses \( O(k) \) space.
   - The `comb` vector also uses \( O(k) \) space at each level of recursion.

2. **Result Storage:**
   - The `ans` vector stores all combinations, requiring \( O(k \cdot C(n, k)) \) space to hold the result.

Thus, the overall space complexity is \( O(k \cdot C(n, k)) \).

### Summary

- **Time Complexity:** \( O(k \cdot C(n, k)) \)
- **Space Complexity:** \( O(k \cdot C(n, k)) \)
*/