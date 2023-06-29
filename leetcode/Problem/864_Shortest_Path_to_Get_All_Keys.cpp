class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> start;

        int k = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (islower(grid[i][j])) k++;
                else if (grid[i][j] == '@') start = {i, j};
            }
        }

        vector<int> keys(k, 0);

        vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(1<<k, 0)));

        queue<vector<int>> q;

        q.push({0, start[0], start[1], 0});
        vector<vector<int>> moves = {{-1,0},{1,0},{0,-1},{0,1}};

        while (!q.empty()) {
            int step = q.front()[0], x = q.front()[1], y = q.front()[2], state = q.front()[3];
            q.pop();

            if (state == (1<<k)-1) return step;
            if (visited[x][y][state]) continue;
            visited[x][y][state] = 1;

            for (int i=0; i<4; i++) {
                int next_x = x + moves[i][0];
                int next_y = y + moves[i][1];
                if (next_x >= 0 && next_x < n && next_y >=0 && next_y < m && grid[next_x][next_y] != '#' && !visited[next_x][next_y][state]) {
                    char ch = grid[next_x][next_y];

                    if ('a' <= ch && ch <= 'f') {
                        int next_state = state|(1<<(ch-'a'));
                        q.push({step+1, next_x, next_y, next_state});
                    }

                    else if ('A' <= ch && ch <= 'F' && 1<<(ch-'A') & state) {
                        q.push({step+1, next_x, next_y, state});
                    }

                    else if (ch=='.' || ch=='@'){
                        q.push({step+1, next_x, next_y, state});
                    }
                }
            }
            /*
            for (int j=state; j>0; j=state&(j-1)) {
                if (visited[x][y][j]) break;
                visited[x][y][j] = 1;
            }
            */
        }

        return -1;
    }
};
