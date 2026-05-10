class Fancy {
public:
    vector<long long> arr;

    long long add = 0;
    long long mul = 1;

    const int MOD = 1e9 + 7;

    // fast power for modular inverse
    long long power(long long a, long long b) {
        long long res = 1;

        while (b > 0) {
            if (b & 1)
                res = (res * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }

    Fancy() {
    }

    void append(int val) {

        // reverse current transformations
        long long invMul = power(mul, MOD - 2);

        long long original =
            ((val - add + MOD) % MOD * invMul) % MOD;

        arr.push_back(original);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {

        if (idx >= arr.size())
            return -1;

        return (arr[idx] * mul + add) % MOD;
    }
};