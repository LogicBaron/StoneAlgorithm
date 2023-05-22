class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        // prime_numbers : 2, 3, 5, 7, 11, 13, 17, 19, 23
        int n = nums.size();
        // vector<int> primes = {2,3};
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29};
        int p = primes.size();
        // vector<int> v(1<<p, 0);
        vector<long long> v((1<<p), 0);
        
        for (int i=0; i<n; i++) {
            int num = nums[i], mark = 0;
            for (int j=0; j<p; j++) {
                if (num == 1) break;
                if (num%primes[j] == 0) {
                    num /= primes[j];
                    mark += (1<<j);
                }
            }
            if (num <= 1) {
                v[mark]++;
            }
        }

        long long mod = 1e9+7;

        long long one_multiplier = 1;
        for (int i=0; i<v[0]; i++) {
            one_multiplier *= 2;
            one_multiplier %= mod;
        }
        vector<long long> dp((1<<p), 0);

        dp[0] = 1;
        for (int i=1; i<(1<<p); i++) {
            if (v[i] == 0) continue;
            for (int j=0; j<(1<<p); j++) {
                if (dp[j] && (j&i)==0) {
                    dp[j|i] += (dp[j]*v[i]);
                    dp[j|i] %= mod;
                }
            }
        }
 
        
        long long rst = 0;
        for (int x=1; x<(1<<p); x++) {
            rst += dp[x];
            rst %= mod;
        }
        rst *= one_multiplier;
        rst %= mod;

        return rst;

    }
};
