/*

Given an integer n, return an array ans of length n + 1 such that for each i
(0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

Do not solve it with built-in functions (i.e., like __builtin_popcount in C++).

*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    int *res = NULL;
    int tmp = 0;
    int bits = 0;

    //
    // Alloc array.
    //

    *returnSize = n + 1;
    res = (int*)malloc(sizeof(int) * *returnSize);
    if (res == NULL) {
        return NULL;
    }

    //
    // Parse bits.
    //

    for (int i = 0; i < *returnSize; i++) {
        tmp = i;
        res[i] = 0;
        while (tmp > 0) {
            res[i] += (tmp & 1);
            tmp >>= 1;

            // bits += (tmp % 2);
            // tmp /= 2;
        }
    }

    return res;
}
