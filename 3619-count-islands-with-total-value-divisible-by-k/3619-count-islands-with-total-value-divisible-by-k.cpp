class Solution {
public:
    // int countIslands(vector<vector<int>>& grid, int k) {
    //     int m = grid.size(), n = grid[0].size();
    //     int ans = 0;

    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (grid[i][j] == 0) continue;

    //             vector<vector<int>> vis(m, vector<int>(n, 0));
    //             queue<pair<int, int>> q;
    //             q.push({i, j});
    //             vis[i][j] = 1;

    //             long long sum = 0;
    //             int first = i * n + j;

    //             while (!q.empty()) {
    //                 auto [x, y] = q.front();
    //                 q.pop();
    //                 sum += grid[x][y];
    //                 first = min(first, x * n + y);

    //                 int dx[] = {1, -1, 0, 0};
    //                 int dy[] = {0, 0, 1, -1};

    //                 for (int d = 0; d < 4; d++) {
    //                     int nx = x + dx[d], ny = y + dy[d];

    //                     if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
    //                         grid[nx][ny] > 0 && !vis[nx][ny]) {
    //                         vis[nx][ny] = 1;
    //                         q.push({nx, ny});
    //                     }
    //                 }
    //             }

    //             if (first == i * n + j && sum % k == 0)
    //                 ans++;
    //         }
    //     }
    //     return ans;
    // }
     int m, n;

    long long dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n ||
            grid[i][j] == 0)
            return 0;

        long long sum = grid[i][j];
        grid[i][j] = 0;

        sum += dfs(grid, i + 1, j);
        sum += dfs(grid, i - 1, j);
        sum += dfs(grid, i, j + 1);
        sum += dfs(grid, i, j - 1);

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long sum = dfs(grid, i, j);

                    if (sum % k == 0)
                        ans++;
                }
            }
        }
        return ans;
    }
};