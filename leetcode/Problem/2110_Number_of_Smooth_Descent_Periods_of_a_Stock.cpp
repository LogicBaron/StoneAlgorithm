class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long rst = 0;

        int l=0, r=1;

        while (r<n) {
            if (prices[r-1] - 1 == prices[r]) {
                r++;
            }
            else {
                long long k = r-l;
                rst += k*(k+1)/2;
                l = r;
                r = l+1;
            }
        }

        long long k = r-l;
        rst += k*(k+1)/2;
        l = r;
        r = l+1;

        return rst;
    }
};
