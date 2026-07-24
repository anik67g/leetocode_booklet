class Solution {
public:

    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2=0;
        for(int i = 1 ;i<n;i++){
            int pick = nums[i];
            if(i>0){
                pick+=prev2;
            }
            int not1 = 0 + prev;
            int curi = max(pick,not1);
            prev2  = prev;
            prev = curi;
        }

        return prev;
    }
};