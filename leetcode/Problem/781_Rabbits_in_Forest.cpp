class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> v(1000, 0);
        for (int answer: answers) {
            v[answer]++;
        }
        int rst = 0;

        for (int i=0; i<1000; i++) {
            if (v[i]>0) {
                int tmp = (v[i]-1)/(i+1);
                rst += (i+1)*(tmp+1);
            }
        }

        return rst;

    }
};
