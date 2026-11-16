/*

Given a positive integer n, write a function that returns the number of set
bits in its binary representation (also known as the Hamming weight).

*/

int hammingWeight(int n) {
    int res = 0;

    while (n > 0) {
        res += (n & 1);
        n >>= 1;
    }

    return res;
}

int hammingWeight(int n) {
    return __builtin_popcount(n);
}
