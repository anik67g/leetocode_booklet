class Solution {
public:
    int climbStairs(int n) {
        // vector<int> dp(n + 1);

        int  prev = 1;
       int prev2 = 1;
         int curri ;
        for (int i = 2; i <= n; i++) {
           curri = prev+prev2;
           prev2 = prev;
           prev  = curri;
        }

        return prev;
    }
};