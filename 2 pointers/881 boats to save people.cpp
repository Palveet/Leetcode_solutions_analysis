class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int sum = 0;
        int ans = 0;
        int i = 0;
        int j = people.size() - 1;
        while (j >= i) {
            if (sum + people[i] + people[j] <= limit) {
                ans++;
                i++;
                j--;
                sum = 0;
            } else if (sum + people[j] <= limit) {
                ans++;
                j--;
                sum = 0;
            } else if (sum + people[i] <= limit) {
                ans++;
                i++;
                sum = 0;
            }
        }
        return ans;
    }
};

//TC: O(NlogN)
//SC: O(1)