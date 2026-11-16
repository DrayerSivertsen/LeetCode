/*

We have two special characters:

The first character can be represented by one bit 0.
The second character can be represented by two bits (10 or 11).
Given a binary array bits that ends with 0, return true if the last character must be a one-bit character.

*/

bool isOneBitCharacter(int* bits, int bitsSize) {
    int i = 0;
    for (i = 0; i < bitsSize - 1; i++) {
        if (bits[i] == 1) {
            i += 1;
        }
    }

    return i == bitsSize - 1;
}
