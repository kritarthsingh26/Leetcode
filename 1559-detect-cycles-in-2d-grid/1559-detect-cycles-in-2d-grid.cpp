class Solution {
public:
    int n, m;
    vector<vector<bool>> visited;
    
    bool dfs(vector<vector<char>>& grid, int x, int y, int px, int py) {
        visited[x][y] = true;
        
        vector<pair<int,int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        for (auto [dx, dy] : dirs) {
            int nx = x + dx;
            int ny = y + dy;
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            
            if (grid[nx][ny] != grid[x][y])
                continue;
            
            if (!visited[nx][ny]) {
                if (dfs(grid, nx, ny, x, y))
                    return true;
            }
            else if (!(nx == px && ny == py)) {
                return true;
            }
        }
        
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        visited.assign(n, vector<bool>(m, false));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    if (dfs(grid, i, j, -1, -1))
                        return true;
                }
            }
        }
        
        return false;
    }
};