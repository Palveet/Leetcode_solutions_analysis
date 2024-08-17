class Solution {
public:
    bool isPrime(int num) {
        if (num <= 1)
            return false;
        if (num == 2 || num == 3)
            return true;
        if (num % 2 == 0 || num % 3 == 0)
            return false;
        for (int i = 5; i <= sqrt(num); i += 6) {
            if (num % i == 0 || num % (i + 2) == 0)
                return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> prime;
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            bool isAPrime = isPrime(i);
            if (isAPrime) {
                prime.push_back(i);
            }
        }
        int first = -1;
        int second = -1;
        if (prime.size() >= 2) {
            int isMin = prime[1] - prime[0];
            first = prime[0];
            second = prime[1];
            for (int i = 1; i < prime.size() - 1; i++) {
                if (prime[i + 1] - prime[i] < isMin) {
                    isMin = prime[i + 1]-prime[i];
                    first = prime[i];
                    second = prime[i+1];
                }
            }
        }
        ans.push_back(first);
        ans.push_back(second);
        return ans;
    }
};

//TC: O(sqrt N)
//SC: O(N)