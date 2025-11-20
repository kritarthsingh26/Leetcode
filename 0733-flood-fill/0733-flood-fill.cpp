class Solution {
public:
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        void bfs(int sr, int sc,int org_color,int color,vector<vector<int>>& image)
        {
            queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;

        while(!q.empty())
        {
            int r=image.size();
        int c=image[0].size();
            pair<int,int>f=q.front();
            q.pop();
            for(int k=0;k<4;k++)
            {
                int i=f.first+dx[k];
                int j=f.second+dy[k];
                if(i<0||i>=r||j<0||j>=c||image[i][j]!=org_color)
                {
                    continue;
                }
                q.push({i,j});

                image[i][j]=color;
            }
        }
        }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int org_color=image[sr][sc];
        

        if(org_color==color)
        {
            return image;
        }
        bfs(sr,sc,org_color,color,image);
        return image;
    }
};