class Solution {
public:
int isallocate(vector<int>&nums , int barrier){
   int n = nums.size();
   int stud = 1;
   long long pages = 0;

   for(int i = 0 ;i<n;i++){
      if(pages+nums[i] <=barrier){
        pages+=nums[i];
      }
      else{
        stud++;
        pages = nums[i];
      }
   }

   return stud;
}
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        long long low= *max_element(nums.begin() ,nums.end());
        
        long long high = accumulate(nums.begin() ,nums.end() , 0LL);

        while(low<=high){
            long long mid = (low+high)/2;
            if(isallocate(nums,mid)>k){
             low =mid+1;
            }
            else{
              high = mid-1;
            }
        }
        return low;
    }
};