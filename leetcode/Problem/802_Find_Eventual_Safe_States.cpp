class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n = graph.size();
        
        vector<int> outdegree(n, 0);
        vector<vector<int>> prev(n);
        queue<int> q;
        for (int i=0; i<n; i++) {
            outdegree[i] = graph[i].size();
            for (int k: graph[i]) {
                prev[k].push_back(i);
            }
            if (outdegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int cur = q.front();
            ans.push_back(cur);
            q.pop();
            for (int k: prev[cur]) {
                outdegree[k]--;
                if (!outdegree[k]) q.push(k);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
