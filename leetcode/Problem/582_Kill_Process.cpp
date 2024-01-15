class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n = 50001;
        vector<vector<int>> adj(n);

        for (int i=0; i<ppid.size(); i++) {
            adj[ppid[i]].push_back(pid[i]);
        }

        vector<int> rst;
        queue<int> q;
        q.push(kill);
        rst.push_back(kill);

        while (q.size()) {
            int cur = q.front();
            q.pop();

            for (int nxt: adj[cur]) {
                q.push(nxt);
                rst.push_back(nxt);
            }
        }

        return rst;
    }
};
