class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>> rst(n);
        vector<int> indegree(n, 0);
        vector<vector<int>> parent(n);
        vector<vector<int>> child(n);

        for (int i=0; i<edges.size(); i++) {
            indegree[edges[i][1]]++;
            parent[edges[i][1]].push_back(edges[i][0]);
            child[edges[i][0]].push_back(edges[i][1]);
        }

        queue<int> q;
        for (int i=0; i<n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i=0; i<child[cur].size(); i++) {
                indegree[child[cur][i]]--;
                for (auto it=rst[cur].begin(); it!=rst[cur].end(); it++) {
                    rst[child[cur][i]].insert(*it);
                }
                rst[child[cur][i]].insert(cur);
                if (indegree[child[cur][i]] == 0) {
                    q.push(child[cur][i]);
                }
            }
        }

        vector<vector<int>> ans(n);

        for (int i=0; i<n; i++) {
            for (auto it=rst[i].begin(); it!=rst[i].end(); it++) {
                ans[i].push_back(*it);
            }
        }

        return ans;
    }
};
