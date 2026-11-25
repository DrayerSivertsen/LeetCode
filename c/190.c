/*

Reverse bits of a given 32 bits signed integer.

*/

int reverseBits(int n) {
    int res = 0;

    n >>= 1;
    for (int i = 1; i < 31; i++) {
        if (n & 1 == 1) {
            res |= (1 << (31 - i));
        }

        n >>= 1;
    }

    return res;
}

int reverseBits(int n) {
    int res = 0;
    for(int i = 0; i < 31; i++) {
        res = res + (n & 1);
        n >>= 1;
        res <<= 1;
    }

    return res;
}

int reverseBits(int n) {
    int res = 0;

    if (n == 0) {
        return 0;
    }

    for(; n; n &= (n - 1)) {
        res += 1 << (31 - __builtin_ctz(n));
    }

    return res;
}
