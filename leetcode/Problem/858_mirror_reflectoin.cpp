class Solution {
public:
    int gcd(int a, int b) {
        int c;
        while (b>0) {
            c = a%b;
            a = b;
            b = c;
        }
        return a;
    }

    int mirrorReflection(int p, int q) {
        int v = q/gcd(p, q);
        int h = p/gcd(p, q);

        if (h%2 == 1 && v%2 == 1) return 1;
        if (h%2 == 1 && v%2 == 0) return 0;
        return 2;
    }
};
