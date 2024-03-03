/*
A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.

Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), return all possible times the watch could represent. You may return the answer in any order.

The hour must not contain a leading zero.

For example, "01:00" is not valid. It should be "1:00".
The minute must consist of two digits and may contain a leading zero.

For example, "10:2" is not valid. It should be "10:02".
*/

char** createArray(int size)
{
    char** array = (char**)malloc(sizeof(char*) * size);

    for (int i = 0; i < size; i++)
    {
        array[i] = (char*)malloc(sizeof(char) * 6);
    }

    return array;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** readBinaryWatch(int turnedOn, int* returnSize) 
{
    char** res = createArray(190);
    int count = 0;

    for (int i = 0; i < 720; i++)
    {
        char h = i / 60;
        char m = i % 60;
        int bitCount = 0;

        while (h > 0)
        {
            if (h % 2 == 1)
                bitCount++;
            h >>= 1;
        }

        while (m > 0)
        {
            if (m % 2 == 1)
                bitCount++;
            m >>= 1;
        }

        if (bitCount == turnedOn)
        {
            snprintf(res[count], 6, "%d:%02d", i / 60, i % 60);
            count++;
        }
    }

    *returnSize = count;
    return res;
}