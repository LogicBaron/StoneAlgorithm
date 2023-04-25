class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        
        for (int i=1; i<=n; i++) {
            // i&(i-1) : reverse right most bit.
            ans[i] = ans[i&(i-1)] + 1;
        }

        return ans;
    }
};
