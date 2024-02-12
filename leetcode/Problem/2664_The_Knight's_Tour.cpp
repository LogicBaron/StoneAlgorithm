class Solution {
public:
    bool dfs(int x, int y, int d, vector<vector<int>> &r) {
        if (d == r.size() * r[0].size()) {
            return true;
        }
        if (x < 0 || x>=r.size() || y<0 || y>=r[0].size() || r[x][y]>=0) {
            return false;
        }
        r[x][y] = d;

        const int dx[] = {1, 1, -1, -1, -2, -2, 2, 2};
        const int dy[] = {-2, 2, -2, 2, -1, 1, -1, 1};
        for (int i=0; i<8; ++i) {
            if (dfs(x+dx[i], y+dy[i], d+1, r)) {
                return true;
            }
        }

        r[x][y] = -1;
        return false;
    }

    vector<vector<int>> tourOfKnight(int m, int n, int r, int c) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        dfs(r, c, 0, ans);
        return ans;
    }
};
