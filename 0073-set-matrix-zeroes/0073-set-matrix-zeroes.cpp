class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int R=matrix.size();
        int C=matrix[0].size();
        vector<bool> row(R, false);
        vector<bool> col(C, false);
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(matrix[i][j]==0)
                {
                    row[i]=true;
                    col[j]=true;
                }
            }

        }
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
                }
        }
       

    }
};