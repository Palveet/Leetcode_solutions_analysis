class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0)
        return false;
    while (n != 1) {
        if (n % 3 != 0)
            return 0;
        n = n / 3;
    }
    return n==1;
    }
};


//TC:O(N)
//SC:O(1)