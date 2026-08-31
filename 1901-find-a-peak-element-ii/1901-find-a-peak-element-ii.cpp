class Solution {
public:

    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        if(n == 1 && m == 1)
            return {0, 0};

        int low = 0;
        int high = m - 1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            int maxi = INT_MIN;
            int row = -1;

            // Find maximum element in current column
            for(int i = 0; i < n; i++) {

                if(mat[i][mid] > maxi) {
                    maxi = mat[i][mid];
                    row = i;
                }
            }

            // Check left and right neighbors
            int left = (mid - 1 >= 0 ? mat[row][mid - 1] : -1);
            int right = (mid + 1 < m ? mat[row][mid + 1] : -1);

            // Current element is a peak
            if(maxi > left && maxi > right) {
                return {row, mid};
            }

            // Search right half
            else if(maxi > left) {
                low = mid + 1;
            }

            // Search left half
            else {
                high = mid - 1;
            }
        }

        return {-1, -1};
    }
};