
class Solution {
public:
int lb(vector<int>& nums, int x){
      int n = nums.size();
      int high = n-1;
      int low = 0 ;
      int ans = -1;
      while(low<=high){
             int mid = (low+high)/2;
             if(nums[mid]>=x){
             ans = mid;
             high = mid -1 ;
             }
             else{
                low = mid+1;
             }

      }
      return ans;

}
int ub(vector<int>& nums, int x){
      int n = nums.size();
      int high = n-1;
      int low = 0 ;
      int ans = -1;
      while(low<=high){
             int mid = (low+high)/2;
             if(nums[mid]>x){
             ans = mid;
             high = mid -1 ;
             }
             else{
                low = mid+1;
             }

      }
      return ans;

}


    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lower = lb(nums , target);
        if(lower==-1 || nums[lower]!=target) return {-1,-1};
     int upper = ub(nums, target);
        if (upper == -1) upper = n;

        return {lower, upper - 1};

    }
};