class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;
        int j = 0;
        int k = 0;
        while(j<haystack.size()){
            if(haystack[j]==needle[k] && k<needle.size()){
                j++;
                k++;
                if(k==needle.size())return i;
            } else {
                i++;
                j = i;
                k = 0; 
            }
        }
        return -1;
    }
};

//TC: O(N*M)
//SC: O(1)

/*
The provided code implements a brute-force solution to the string matching problem, where it searches for the first occurrence of the substring `needle` in the string `haystack`. Let's analyze its time complexity step-by-step.

### Analysis of the Algorithm:

1. **Initialization**: 
   - Three indices `i`, `j`, and `k` are initialized to 0.

2. **Main Loop**:
   - The outer `while` loop runs as long as `j` is less than the size of `haystack`.
   - Inside the loop:
     - If `haystack[j] == needle[k]` and `k` is less than the size of `needle`:
       - Increment `j` and `k`.
       - If `k` equals the size of `needle`, it means `needle` is found in `haystack`, and the function returns `i` (the starting index of the match).
     - If the characters don't match or `k` is not less than the size of `needle`:
       - Increment `i`.
       - Set `j` to `i`.
       - Reset `k` to 0.

### Worst-Case Time Complexity:

In the worst case, the algorithm might have to compare each character of `needle` with a large portion of `haystack`.

- For each starting index `i` in `haystack` (which ranges from 0 to `n-1`, where `n` is the length of `haystack`), the algorithm might have to compare up to `m` characters (where `m` is the length of `needle`) until it finds a mismatch or a match.
- If there is no match, the algorithm shifts the starting index `i` by one and repeats the comparison.

Thus, in the worst case, the number of comparisons can be roughly the product of the lengths of `haystack` and `needle`.

### Mathematical Representation:

If `n` is the length of `haystack` and `m` is the length of `needle`, the worst-case time complexity can be represented as:

\[ O(n \times m) \]

### Example of Worst Case:

Consider the worst-case scenario where `haystack` contains repeated characters that are almost the same as `needle`, but the match occurs only at the end (or not at all). For example:

- `haystack` = "aaaaaa...aaab" (n 'a's followed by 1 'b')
- `needle` = "aaaab"

The algorithm will repeatedly compare each segment of `haystack` of length `m` with `needle`, resulting in `n - m + 1` comparisons, each of which can take up to `m` comparisons.

### Conclusion:

The time complexity of the given code for the `strStr` function is \( O(n \times m) \).
*/