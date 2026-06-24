class Solution {
private:
    void solve(int i, vector<int>& temp, vector<vector<int>>& ans, int k,
          int target) {
        if (target < 0 || temp.size() > k) {
            return;
        }
        if (target == 0 && temp.size() == k) {
            ans.push_back(temp);
            return;
        }

    if(i<10){
        temp.push_back(i);
        solve(i + 1, temp, ans, k, target - i);
        temp.pop_back();
        solve(i + 1, temp, ans, k, target);}
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;

        if (k > n)
            return ans;

        solve(1, temp, ans, k, n);

        return ans;
    }
};