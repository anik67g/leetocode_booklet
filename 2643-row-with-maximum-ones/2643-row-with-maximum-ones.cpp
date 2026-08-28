class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) 
    {
        
        //o(m*n)
        int row_num=0;
        int num_ones=0;
        for (int i=0;i<mat.size();i++)
        {
            int temp_count=0;
            for (int j=0;j<mat[0].size();j++)
            {
                if (mat[i][j]==1){temp_count++;}
            }
            if (temp_count>num_ones)
            {
                row_num=i;
                num_ones=temp_count;
            }
        }

        return {row_num,num_ones};
        
    }
};