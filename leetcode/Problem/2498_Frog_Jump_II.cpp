class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int diff1 = INT_MIN, diff2=INT_MIN;
        if (n==2) {
            return abs(stones[1]-stones[0]);
        }

        for (int i=2; i<n; i+=2) {
            diff1 = max(diff1, abs(stones[i]-stones[i-2]));
        }

        for (int i=3; i<n; i+=2) {
            diff1 = max(diff1, abs(stones[i]-stones[i-2]));
        }

        return max(diff1, diff2);
    }
};
