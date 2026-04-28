class Solution {
public:
    long long C(long long n) {
        if (n < 2) return 0;
        return n * (n - 1) / 2;
    }

    int distributeCandies(int n, int limit) {
        auto f = [&](long long x) {
            if (x < 0) return 0LL;
            return (x + 2) * (x + 1) / 2;
        };

        long long ans = f(n)
                      - 3 * f(n - (limit + 1))
                      + 3 * f(n - 2 * (limit + 1))
                      - f(n - 3 * (limit + 1));

        return (int)ans;
    }
};