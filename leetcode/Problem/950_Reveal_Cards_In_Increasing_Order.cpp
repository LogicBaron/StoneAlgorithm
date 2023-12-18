class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> ans(n);

        sort(deck.begin(), deck.end());
        int step = 0;
        int flag = 1;
        int pos = 0;
        while (pos<n) {
            if (ans[step]==0) {
                if (flag) {
                    ans[step] = deck[pos];
                    pos++;
                }
                flag = (flag+1)%2;
            }
            step = (step+1)%n;
        }

        return ans;
    }
};
