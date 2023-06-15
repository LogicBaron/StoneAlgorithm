class Solution {
public:
    double findProbability(int index, int n, vector<vector<double>>& memo, vector<double>& prob, int target) {
        if (target<0) return 0;
        if (index == n) return target==0 ? 1: 0;
        if (memo[index][target] != -1) return memo[index][target];
        memo[index][target] = findProbability(index+1, n, memo, prob, target-1)*prob[index] + findProbability(index+1, n, memo, prob, target) * (1-prob[index]);
        return memo[index][target];
    }

    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<vector<double>> memo(n, vector<double>(target+1, -1));
        return findProbability(0, n, memo, prob, target);
    }
};
