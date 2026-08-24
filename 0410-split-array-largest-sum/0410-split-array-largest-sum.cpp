class Solution {
private:
    vector<int> prefixSum;
    int dp[51][1001];

    int solve(const vector<int>& nums, int k, int idx){
        int n = nums.size();

        if(idx >= n) return 0;

        if(k == 1) return prefixSum[n] - prefixSum[idx];

        if(dp[k][idx] != -1) return dp[k][idx];

        int ans = INT_MAX;

        for(int i=idx; i<=n-k; i++){
            int leftPartition = prefixSum[i+1] - prefixSum[idx];
            int rightPartition = solve(nums, k-1, i+1);

            int mxValueBetweenPartiton = max(leftPartition, rightPartition);

            ans = min(ans, mxValueBetweenPartiton);
        }

        return dp[k][idx] = ans;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        prefixSum.assign(n+1, 0);
        for(int i=0; i<n; i++) prefixSum[i+1] = prefixSum[i] + nums[i];

        memset(dp, -1, sizeof(dp));
        
        return solve(nums, k, 0);
    }
};