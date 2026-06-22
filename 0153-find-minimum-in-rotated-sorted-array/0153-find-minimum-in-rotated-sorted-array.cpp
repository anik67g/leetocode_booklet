class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans= INT_MAX;
        int  low = 0 ; int high = nums.size()-1;
        while(low<=high){

            int mid= (low+high)/2;
            // this is for checking the left part of the array is sorted or not..
            if(nums[low]<= nums[mid]){
                ans=min(ans , nums[low]);
                low =mid+1;
            }
            // the right part of the array is sorted or not..
            else {
                         ans = min(ans ,nums[mid]);
                         high = mid-1;
            }
        }
        return ans;
    }
};