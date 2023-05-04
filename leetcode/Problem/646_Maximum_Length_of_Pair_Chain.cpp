class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b){
            if (a[1]==b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });

        int rst = 0;
        int cur_end = INT_MIN;
        for (vector<int> pair: pairs) {
            if (pair[0] > cur_end) {
                rst++;
                cur_end = pair[1];
            }
        }

        return rst;
    }
};
