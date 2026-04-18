class Solution {
public:
        int m,n;
        int dx[4]={-1,0,0,1};
        int dy[4]={0,-1,1,0};
        int t[201][201];

        int dfs(int i,int j,vector<vector<int>>& matrix)
        {
           
            int maxlen=1;
            if(t[i][j]!=-1)
            {
                return t[i][j];
            }
            for(int d=0;d<4;d++)
            {
                int nx=i+dx[d];
                int ny=j+dy[d];


            
            if(nx>=0 && ny>=0 && nx<m && ny <n && matrix[nx][ny]>matrix[i][j])
            {
                maxlen=max(maxlen,1+dfs(nx,ny,matrix));
            }}

            return t[i][j]=maxlen;
        
        }
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
         m=matrix.size();
         n=matrix[0].size();
        memset(t,-1,sizeof(t));

        int ans=0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=max(ans,dfs(i,j,matrix));
            }
        }
        return ans;
    }
};