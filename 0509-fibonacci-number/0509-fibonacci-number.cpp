class Solution {
public:
    int helper(int n, vector<int>& dp) {
        if (dp[n] != -1)
            return dp[n];

        dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
        return dp[n];
    }

    int fib(int n) {
        vector<int> dp(n + 1, -1);
        if (n >= 0) dp[0] = 0;
        if (n >= 1) dp[1] = 1;
        return helper(n, dp);
    }
};