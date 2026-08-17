class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;

        for (int i = 0; i < nums.size(); i++) {

            if (temp.empty() || nums[i] > temp.back()) {
                temp.push_back(nums[i]);
            }
            else {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i])
                          - temp.begin();

                temp[ind] = nums[i];
            }
        }

        return temp.size();
    }
};