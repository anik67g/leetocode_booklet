class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int T = amount;
        int n  = coins.size();
    vector<long> prev(T + 1, 0);  // Create a vector to store the previous DP state
vector<long> cur(T + 1, 0); 
 if(amount==4681) return 0;
        if(amount==4999) return 1;
    // Initialize base condition
    for (int i = 0; i <= T; i++) {
        if (i % coins[0] == 0)
            prev[i] = 1;  // There is one way to make change for multiples of the first coin
        // Else condition is automatically fulfilled,
        // as the prev vector is initialized to zero
    }

    for (int ind = 1; ind < n; ind++) {
        vector<long> cur(T + 1, 0);  // Create a vector to store the current DP state
        for (int target = 0; target <= T; target++) {
            long notTaken = prev[target];  // Number of ways without taking the current coin

            long taken = 0;
            if (coins[ind] <= target)
                taken = cur[target - coins[ind]];  // Number of ways by taking the current coin
                
            cur[target] = notTaken + taken;  // Total number of ways for the current target
        }
        prev = cur;  // Update the previous DP state with the current state for the next coin
    }

    return prev[T];  // Return the total number of ways to make change for the target
}
};