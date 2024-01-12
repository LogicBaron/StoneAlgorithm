class Solution {
public:
    int hammingDistance(int x, int y) {

        int ans = 0;

        int a = x ^ y;

        while (a) {
            if (a % 2 == 1) ans += 1;
            a = a >> 1;
        }
        return ans;
    }
};
