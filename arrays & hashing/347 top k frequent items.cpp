class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]){
                mp[nums[i]]++;
            }else{
                mp[nums[i]]=1;
            }
        }
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
        for(auto i=mp.begin();i!=mp.end();i++){
            minh.push({i->second,i->first});
            if(minh.size()>k)minh.pop();
        }
        while(minh.size()>0){
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
};

//GPT Notes

/*

Let's re-examine the time complexity analysis to clarify why \(O(N \log k)\) is considered the dominant term in this context.

### Time Complexity Breakdown

#### 1. Building the Frequency Map
```cpp
unordered_map<int, int> mp;
for(int i = 0; i < nums.size(); i++){
    mp[nums[i]]++;
}
```
- **Time Complexity:** \(O(N)\)
- This loop runs \(N\) times (where \(N\) is the number of elements in `nums`).
- Each operation of inserting or updating the count in the `unordered_map` is \(O(1)\) on average.

#### 2. Building the Min-Heap
```cpp
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
for(auto i = mp.begin(); i != mp.end(); i++){
    minh.push({i->second, i->first});
    if(minh.size() > k) minh.pop();
}
```
- **Time Complexity:** \(O(M \log k)\)
- This loop runs \(M\) times (where \(M\) is the number of unique elements in `nums`).
- Each insertion into the min-heap takes \(O(\log k)\) because the heap size is maintained at most \(k\).
- In the worst case, \(M\) could be as large as \(N\).

#### 3. Extracting the Top \(k\) Elements
```cpp
while(minh.size() > 0){
    ans.push_back(minh.top().second);
    minh.pop();
}
```
- **Time Complexity:** \(O(k \log k)\)
- This loop runs \(k\) times (extracting \(k\) elements from the heap).
- Each `pop` operation from the min-heap takes \(O(\log k)\).

### Combining the Complexities
- **Building the Frequency Map:** \(O(N)\)
- **Building the Min-Heap:** \(O(M \log k)\)
- **Extracting the Top \(k\) Elements:** \(O(k \log k)\)

#### Considering \(M \leq N\)
- In the worst case, \(M\) (the number of unique elements) could be equal to \(N\).
- Hence, \(O(M \log k)\) becomes \(O(N \log k)\).

### Dominance of \(O(N \log k)\)
When comparing \(O(N)\), \(O(N \log k)\), and \(O(k \log k)\):

1. **\(O(N)\):** Linear in terms of the number of elements.
2. **\(O(N \log k)\):** Linear with an additional logarithmic factor that depends on \(k\).
3. **\(O(k \log k)\):** Depends only on \(k\).

In typical scenarios where \(k\) is much smaller than \(N\) (e.g., finding the top 10 frequent elements in a list of thousands), \(O(k \log k)\) becomes relatively insignificant compared to \(O(N \log k)\). Thus, \(O(N \log k)\) is the term that grows fastest with \(N\).

### Conclusion
The overall time complexity is dominated by the term that grows fastest with \(N\):

\[ O(N) + O(N \log k) + O(k \log k) \approx O(N \log k) \]

This is why \(O(N \log k)\) is considered the dominant term in this context.

*/