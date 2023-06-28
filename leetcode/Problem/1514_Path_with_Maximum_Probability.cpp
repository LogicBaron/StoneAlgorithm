class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<double> prob(n, 0.);
        vector<bool> visited(n, false);
        visited[start] = true;
        prob[start] = 1.;
        int cur = start;

        for (int step=0; step<n; step++) {
            visited[cur] = true;
            if (cur == end) {
                cout << step;
                return prob[cur];
            }
            for (int i=0; i<adj[cur].size(); i++) {
                if (!visited[adj[cur][i].first]) {
                    prob[adj[cur][i].first] = max(prob[adj[cur][i].first], prob[cur] * adj[cur][i].second);
                }
            }
            double tmp_max_prob = -1;
            for (int i=0; i<n; i++) {
                if (!visited[i] && prob[i] >= tmp_max_prob) {
                    cur = i;
                    tmp_max_prob = prob[cur];
                }
            }
        }

        return 0.0;
    }
};
