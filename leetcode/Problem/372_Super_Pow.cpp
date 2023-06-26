class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int n = b.size();
        vector<int> coef(n, 1);
        int mod = 1337;

        if (a==1) return 1;
        
        coef[n-1] = a%mod;
        if (n>1) {
            int k = n-2;
            while (k>=0) {
                for (int i=0; i<10; i++) {
                    coef[k] = coef[k]*coef[k+1];
                    coef[k] = coef[k]%mod;
                }
                k--;
            }
        }

        int rst = 1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<b[i]; j++) {
                rst = rst * coef[i];
                rst = rst%mod;
            }
        }

        return rst;
    }
};
