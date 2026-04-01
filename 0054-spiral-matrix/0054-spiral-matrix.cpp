class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int>answer;
        int m=matrix.size();
        int n=matrix[0].size();
        int sr=0;
        int sc=0;
        int er=m-1;
        int ec=n-1;
        while(sc<=ec && sr<=er) 
        {
            //top
            for(int j=sc;j<=ec;j++)
            {
                answer.push_back(matrix[sr][j]);
            }
            //vertical
            for(int i=sr+1;i<=er;i++)
            {
                answer.push_back(matrix[i][ec]);
            }

            //bottom
            for(int j=ec-1;j>=sc;j--)
            {
                if(sr==er)
                {
                    break;
                }
                answer.push_back(matrix[er][j]);
            }

            //horizontal

            for(int i=er-1;i>=sr+1;i--)
            {
                if(sc==ec)
                {
                    break;
                }
                answer.push_back(matrix[i][sc]);
            }
            sc++;
            sr++;
            er--;
            ec--;
        } 
        return answer;
    }
};