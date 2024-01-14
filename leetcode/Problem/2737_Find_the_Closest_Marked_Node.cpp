class Solution {
public:
    int minimumDistance(int n, vector<vector<int>>& edges, int s, vector<int>& marked) {
        vector<vector<int>> adj(n, vector<int>(n, INT_MAX));

        for (vector<int> edge: edges) {
            adj[edge[0]][edge[1]] = min(adj[edge[0]][edge[1]], edge[2]);
        }

        vector<vector<pair<int, int>>> a(n);

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (adj[i][j] != INT_MAX) {
                    a[i].push_back({j, adj[i][j]});
                }
            }
        }

        int rst = INT_MAX;

        priority_queue<pair<int, int>> pq;

        pq.push({0, s});
        vector<int> dist(n, INT_MAX);
        dist[s] = 0;

        while (pq.size()) {
            int cost = -pq.top().first;
            int cur = pq.top().second;
            pq.pop();

            if (dist[cur] < cost) continue;

            for (auto next: a[cur]) {
                int nxt = next.first;
                int nxtDist = next.second + cost;

                if (nxtDist < dist[nxt]) {
                    dist[nxt] = nxtDist;
                    pq.push({-nxtDist, nxt});
                }
            }
        }

        for (int mark: marked) {
            rst = min(rst, dist[mark]);
        }

        return rst == INT_MAX?-1:rst;
    }
};
