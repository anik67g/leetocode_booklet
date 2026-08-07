class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int totalSum = 0;

        for(int x : nums)
            totalSum += x;

        // Impossible cases
        if(abs(target) > totalSum)
            return 0;

        if((target + totalSum) % 2 != 0)
            return 0;

        int req = (target + totalSum) / 2;

        vector<int> dp(req + 1, 0);

        dp[0] = 1;

        for(int num : nums) {

            for(int s = req; s >= num; s--) {

                dp[s] += dp[s - num];

            }

        }

        return dp[req];
    }
};