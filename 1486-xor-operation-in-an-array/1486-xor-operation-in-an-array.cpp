class Solution {
public:
    int xorOperation(int n, int start) {
        int nums[n];
        int xor1= 0;
        for(int  i =  0 ;i<n ;i++){
            nums[i]= start+2*i;
   xor1= xor1^nums[i];
        }
        return xor1;
       
    }
};