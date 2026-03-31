class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        queue<pair<int,int>> q;
        
        // Step 1: Push all land cells
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i, j});
                }
            }
        }

        // Edge case: all water or all land
        if(q.empty() || q.size() == n * n)
        {
            return -1;
        }

        int dist = -1;
        vector<int> dir = {0, 1, 0, -1, 0};

        // Step 2: BFS
        while(!q.empty())
        {
            int size = q.size();
            dist++;

            for(int k = 0; k < size; k++)
            {
                auto [x, y] = q.front();
                q.pop();

                for(int d = 0; d < 4; d++)
                {
                    int nx = x + dir[d];
                    int ny = y + dir[d + 1];

                    if(nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0)
                    {
                        grid[nx][ny] = 1; // mark visited
                        q.push({nx, ny});
                    }
                }
            }
        }

        return dist;
    }
};