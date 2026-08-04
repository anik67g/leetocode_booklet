class Solution {
    public:
      bool subsetSumToK(int n, int k, vector<int> &arr) {
        // Initialize a 2D DP array with dimensions (n x k+1) to store subproblem results
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        // Base case: If the target sum is 0, we can always achieve it by taking no elements
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        // Base case: If the first element of 'arr' is less than or equal to 'k', set dp[0][arr[0]] to true
        if (arr[0] <= k) {
            dp[0][arr[0]] = true;
        }

        // Fill the DP array iteratively
        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= k; target++) {
                // If we don't take the current element, the result is the same as the previous row
                bool notTaken = dp[ind - 1][target];

                // If we take the current element, subtract its value from the target and check the previous row
                bool taken = false;
                if (arr[ind] <= target) {
                    taken = dp[ind - 1][target - arr[ind]];
                }

                // Store the result in the DP array for the current subproblem
                dp[ind][target] = notTaken || taken;
            }
        }

        // The final result is stored in dp[n-1][k]
        return dp[n - 1][k];
    }


    bool canPartition(vector<int>& nums) {
        int n  = nums.size();
        int totsum=0;
        for(int i = 0 ;i<n;i++){
            totsum+=nums[i];
        }
        int target = totsum/2;
        if(totsum%2==1) return false;
        return subsetSumToK( n ,target,nums );
    }
};