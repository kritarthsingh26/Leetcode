class Solution {
public:
        int m,n;
        int dx[8]={-1,0,0,1,-1,-1,1,1};
        int dy[8]={0,-1,1,0,-1,1,-1,1};
        int t[1001][1001];
        const int MOD = 1e9 + 7;

        int dfs(int i,int j,vector<vector<int>>& grid)
        {
            if(t[i][j]!=-1)
            {
                return t[i][j];
            }
            int ways=1;
           

            for(int d=0;d<4;d++)
            {
                int nx=i+dx[d];
                int ny=j+dy[d];

                if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]>grid[i][j])
                {
                   ways = (ways + dfs(nx, ny, grid)) % MOD;
                }
            }
            return t[i][j]=ways;
        }
    int countPaths(vector<vector<int>>& grid) 
    {
         m=grid.size();
         n=grid[0].size();
        int count=0;
        memset(t,-1,sizeof(t));
         long long ans = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans = (ans + dfs(i, j, grid)) % MOD;
            }
        }
        return ans;
        
    }
};