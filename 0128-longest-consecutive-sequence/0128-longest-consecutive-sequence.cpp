class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        int longest = 1;
        unordered_set<int> st;
        // put all the arrays elements in the set because set contains only unique elements-->
        for(int i =0 ; i<n ;i++){
            st.insert(nums[i]);
        }
        for(auto it : st){
            // check if it is a starting number 
            if(st.find(it-1)==st.end()){
                int count =1;
                int x = it;
            
            while(st.find(x+1)!=st.end()){
                x++;
                count++;
            }
            longest = max(longest , count);
            }
        }
        return longest;


    }
};