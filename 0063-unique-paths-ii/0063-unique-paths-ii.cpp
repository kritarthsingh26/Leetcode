class Solution {
public:
   
        int t[101][101];
        int solve(int m,int n,int i,int j,vector<vector<int>>& obstacleGrid)
        {
            if(i>m-1 || j>n-1)
            {
                return 0;
            }
            if(obstacleGrid[i][j]==1)
            {
                return 0;
            }

             if(t[i][j]!=-1)
            {
                return t[i][j];
            }
            if(i==m-1 && j==n-1)
            {
                return 1;
            }
           

            int right=solve(m,n,i,j+1,obstacleGrid);
            int down=solve(m,n,i+1,j,obstacleGrid);
            return t[i][j]=(right+down);
        }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 

    {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        int i=0;
        int j=0;
        memset(t,-1,sizeof(t));

        return solve(m,n,i,j,obstacleGrid);
    }
};