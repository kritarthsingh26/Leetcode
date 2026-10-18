class Solution {
public:
        int dx[4]={0,1,-1,0};
        int dy[4]={-1,0,0,1};
    void dfs(vector<vector<char>>& board,int x,int y)
    {
        int m = board.size();
        int n = board[0].size();

        board[x][y]='#';

        for(int i=0;i<4;i++)
        {
            int ii=x+dx[i];
            int jj=y+dy[i];
            if(ii>=0 && ii<=m-1 && jj>=0 && jj<=n-1 &&board[ii][jj]=='O')
            {
                dfs(board,ii,jj);
            }
        }
    }
    void solve(vector<vector<char>>& board) 
    {
         int m=board.size();
         int n=board[0].size();
         // top and bottom
         for(int i=0;i<n;i++)
         {
            if(board[0][i]=='O')
            {
                dfs(board,0,i);
            }
            if(board[m-1][i]=='O')
            {
                dfs(board,m-1,i);
            }
         }   
         // left and right
          for(int i=0;i<m;i++)
         {
            if(board[i][0]=='O')
            {
                dfs(board,i,0);
            }
            if(board[i][n-1]=='O')
            {
                dfs(board,i,n-1);
            }
         } 
         for(int i=0;i<m;i++)
         {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O' )
                {
                    board[i][j]='X';
                }
                else if(board[i][j]=='#')
                {
                    board[i][j]='O';
                }

            }
         }
    }
};