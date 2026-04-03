class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) 
    {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>ans;

        int low=0;
        int high=n-1;
        int sr=0;
        int er=m-1;
        int left;
        int right;

        while(low<=high)
        {
            int mid=low+(high-low)/2;
            // find the largest element in mid col
            int maxRow = 0;
            for (int i = 0; i < m; i++)
            {
                if (mat[i][mid] > mat[maxRow][mid])
                {
                    maxRow = i;
                }
            }
            if (mid - 1 >= 0)
                left = mat[maxRow][mid - 1];
            else
                left = -1;

            if (mid + 1 < n)
                right = mat[maxRow][mid + 1];
            else
                right = -1;



            if(mat[maxRow][mid]>left && mat[maxRow][mid]>right)
            {
                ans.push_back(maxRow);
                ans.push_back(mid);
                return ans;
            }
            if(mat[maxRow][mid]<left)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }

        }
        return ans; 
    }
};