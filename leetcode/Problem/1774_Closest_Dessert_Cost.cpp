class Solution {
public:
    int target;

    int closest(int a, int b) {
        if (a==0) return b;
        if (b==0) return a;
        if (abs(target-a)==abs(target-b)) return a<b? a:b;
        return abs(target-a)<abs(target-b)?a:b;
    }

    int dfs(vector<int>& top, int i, int sum) {
        if (i>=top.size()) return sum;

        int a = dfs(top, i+1, sum+top[i]);
        int b = dfs(top, i+1, sum+top[i]*2);
        int c = dfs(top, i+1, sum);
        sum = closest(a, closest(b, c));
        return sum;
    }

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int t) {
        int ans;
        int n = baseCosts.size();
        
        target = t;

        for (int i=0; i<n; i++) {
            ans = closest(dfs(toppingCosts, 0, baseCosts[i]), ans);
        }

        return ans;
    }
};
