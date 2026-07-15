class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xore = 0 ;
        for(int  i = 0 ;i<nums.size();i++){
            xore = xore^nums[i];
        }
        return xore;
    }
};