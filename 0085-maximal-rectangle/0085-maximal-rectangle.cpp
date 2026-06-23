class Solution {
public:
int largestRectangleArea(vector<int> &histo) {
        stack<int> st;  
        int maxA = 0;  // Variable to keep track of the maximum area
        int n = histo.size();

        // Loop through each bar including an imaginary bar at the end
        for (int i = 0; i <= n; i++) {
            // While current bar is smaller than the top of the stack or we reached the end
            while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
                int height = histo[st.top()]; // Get the height of the bar at top of the stack
                st.pop(); // Remove that bar

                int width;
                if (st.empty()) {
                    width = i; // All bars before were higher
                } else {
                    width = i - st.top() - 1; // Width between current index and index at top of stack
                }

                // Calculate area and update maximum area
                maxA = max(maxA, width * height);
            }
            // Push current index into stack
            st.push(i);
        }
        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxarea = 0;
        if(matrix.empty()) return 0;
        int m = matrix[0].size();
        vector<int> height(m,0);
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j= 0 ;j<m;j++){
                if(matrix[i][j]=='1'){
                    height[j]++;
                }
                else{
                    height[j]=0;
                }


            }
            int area =largestRectangleArea(height); 
            maxarea = max(area,maxarea);
        }
        return maxarea;
    }
};