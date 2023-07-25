class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();
        long long res = 0;
        vector<int> dp(n);
        unordered_map<int, int> count;
        for (int i=0; i<n; i++) {
            int mask = bit(dp, parent, s, i);
            // root 에서 node 까지 알파벳 등장 횟수가 짝수면 0, 홀수면 1로 표시.
            // dfs 후 이렇게 연산할 수 있는 현재 노드 ~ target 노드의 path 가 단 하나로 결정되는 tree 형태라서 그럼.
            // root ~ common ancestor 까지는 알아서 ^ 연산에 의해 0회로 지워진다.
            for (int j=0; j<26; j++) {
                res += count.count(mask ^ (1<<j)) ? count[mask ^ (1<<j)] : 0;
                // 지금까지 봤던 0~n 까지의 node 들 중, 현재 mask^(1<<j) 와 같은 노드가 있으면,
                // 현재 노드 ~ target node 까지의 path 는 (1<<ㅓ) 만 하나고 나머지는 짝수인 path 가 된다.
            }
            res += count[mask]++;
            // 아무것도 안 더하고 0~n 까지의 노드 들 중, 현재 mask 와 같은 노드가 있으면,
            // 현재 node ~ target node 까지의 path 는 모든 글자가 짝수인 path 가 된다.
            // 다음 연산부터는 현재 노드가 탐색 대상 노드들 중 하나가 되므로 1 을 더해준다.
        }

        return res;
    }

    int bit(vector<int>& dp, vector<int>& parent, string& s, int i) {
        // -1 노드는 어차피 갈 수 없으므로 처리 안해준다.
        if (i>0 && dp[i]==0) {
            dp[i] = bit(dp, parent, s, parent[i]) ^ (1<<(s[i]-'a'));
        }
        return dp[i];
    }
};
