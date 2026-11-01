class Solution {
public:
    int minMoves(vector<int>& nums) {
        int cnt =0;
        int n  = nums.size();
        int mn = *min_element(nums.begin() ,nums.end());
        for(int i = 0;i<n;i++){

           cnt += nums[i]-mn;
            
        }
return cnt;
    }
};