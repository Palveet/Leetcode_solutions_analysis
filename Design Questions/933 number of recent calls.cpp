class RecentCounter {
public:
    unordered_set<int>s;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int count =0;
        s.insert(t);
        for(const auto& ele:s){
            if(ele>=t-3000 && ele <=t){
                count++;
            }
        }
        return count;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

//TC: O(N)
//SC: O(N)


//Solution 2 : O(1) Solution
class RecentCounter {
public:
     std::queue<int> q;
    
    RecentCounter() { }
    
    int ping(int t) {
        q.push(t);
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};

//TC:O(1)
//SC:O(N)