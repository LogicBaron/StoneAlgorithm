class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_ever = INT_MAX;
        int profit = 0;

        for (int i=0; i<prices.size(); i++) {
            profit = max(profit, prices[i]-min_ever);
            min_ever = min(min_ever, prices[i]);
        }

        return profit;
    }
};
