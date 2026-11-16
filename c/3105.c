/*

You are given an array of integers nums. Return the length of the longest
subarray of nums which is either strictly increasing or strictly decreasing.

*/

int longestMonotonicSubarray(int* nums, int numsSize) {
    int incr = 0, decr = 0;
    int max = 0, tmp = 0;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i - 1] < nums[i]) {
            incr += 1;
            decr = 0;
        } else if (nums[i - 1] > nums[i]) {
            incr = 0;
            decr += 1;
        } else {
            incr = 0;
            decr = 0;
        }

        tmp = fmax(incr, decr);
        max = fmax(max, tmp);
    }

    return max + 1;
}
