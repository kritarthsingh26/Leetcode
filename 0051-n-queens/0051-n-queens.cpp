class Solution {
public:
        bool issafe(vector<string>&board,int row,int column,int n)
        {
            for(int j=0;j<n;j++)
            {
                if(board[row][j]=='Q')
                {
                    return false;
                }
            }
            for(int i=0;i<n;i++)
            {
                if(board[i][column]=='Q')
                {
                    return false;
                }
            }
            for(int i=row,j=column;i>=0&&j>=0;i--,j--)
            {
                if(board[i][j]=='Q')
                {
                    return false;
                }
            }
            for(int i=row,j=column;i>=0&&j<n;i--,j++)
            {
                if(board[i][j]=='Q')
                {
                    return false;
                }
            }
            return true;

        }
        void queens(vector<string>&board,int row,int n,vector<vector<string>>&answer)
        {
            if(row==n)
            {
                answer.push_back({board});
                return;
            }
            for(int j=0;j<n;j++)
            {
                if(issafe(board,row,j,n))
                {
                board[row][j]='Q';
                queens(board,row+1,n,answer);
                board[row][j]='.';
            }
        }}
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>answer;

        queens(board,0,n,answer);
        return answer;
    }
};