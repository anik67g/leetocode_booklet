class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans1;
        for (int i=1;i<=numRows ;i++){
        long long val =1;
        
        vector<int> ans;
        ans.push_back(1);
        for(int col = 1 ; col<i ; col++){
            val *=(i-col);
            val/=col;
            ans.push_back(val);
        }
        
        ans1.push_back(ans);
    }
    return ans1;
    }
};