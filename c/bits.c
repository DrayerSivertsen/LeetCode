#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stdbool.h>

uint8_t  x = 0b10101100;
uint8_t  y = 0b00001111;
uint8_t  z = 0b01010101;

uint32_t n = 0b00001000;
uint32_t mask;
uint32_t res;


//
// ============================================================
// 1. BASIC BITWISE OPERATIONS
// ============================================================
//


// ------------------------------------------------------------
// AND (&)
//
// Sets a bit only when BOTH corresponding bits are 1.
//
//   10101100
// & 00001111
// ----------
//   00001100
//

res = x & y;


// ------------------------------------------------------------
// OR (|)
//
// Sets a bit when EITHER corresponding bit is 1.
//
//   10101100
// | 00001111
// ----------
//   10101111
//

res = x | y;


// ------------------------------------------------------------
// XOR (^)
//
// Sets a bit when the corresponding bits are DIFFERENT.
//
//   10101100
// ^ 00001111
// ----------
//   10100011
//

res = x ^ y;


// ------------------------------------------------------------
// NOT (~)
//
// Flips every bit: 1 becomes 0, 0 becomes 1.
//
//   10101100
// ----------
//   01010011
//
// Note: uint8_t promotes to int before ~ is applied.
// Cast back to uint8_t when you want an 8-bit result.
//

res = (uint8_t)~x;


// ------------------------------------------------------------
// LEFT SHIFT (<<)
//
// Shifts bits left.
// Vacated rightmost bits become 0.
//
//   00001000
// <<        2
// ----------
//   00100000
//
// Equivalent to multiplying by 2^2 when no overflow occurs.
//

res = n << 2;


// ------------------------------------------------------------
// RIGHT SHIFT (>>)
//
// Shifts bits right.
// For unsigned integers, vacated leftmost bits become 0.
//
//   00100000
// >>        2
// ----------
//   00001000
//
// Equivalent to dividing by 2^2 for unsigned integers.
//

res = n >> 2;



//
// ============================================================
// 2. SET, CLEAR, TOGGLE, AND CHECK INDIVIDUAL BITS
// ============================================================
//


// Bit positions, counting from the right:
//
//   bit:  7 6 5 4 3 2 1 0
//         1 0 1 0 1 1 0 0
//                         ^ bit 0
//
//   1u << 3 creates:
//
//         00001000
//              ^
//            bit 3
//


// ------------------------------------------------------------
// SET A BIT
//
// Use OR to force a bit to 1.
//
//   10101100
// | 00001000
// ----------
//   10101100
//
// Bit 3 is set to 1.
// If it was already 1, nothing changes.
//

x |= (1u << 3);


// ------------------------------------------------------------
// CLEAR A BIT
//
// Use AND with an inverted mask to force a bit to 0.
//
//   10101100
// & 11110111
// ----------
//   10100100
//
// ~00001000 = 11110111 (8-bit representation)
// Bit 3 is cleared.
//

x &= ~(1u << 3);


// ------------------------------------------------------------
// TOGGLE A BIT
//
// Use XOR to flip a bit.
//
//   10101100
// ^ 00001000
// ----------
//   10100100
//
// If the bit was 0, it becomes 1.
// If the bit was 1, it becomes 0.
//

x ^= (1u << 3);


// ------------------------------------------------------------
// CHECK WHETHER A BIT IS SET
//
// AND isolates the bit we care about.
//
//   10101100
// & 00001000
// ----------
//   00001000
//
// Nonzero means bit 3 is set.
// Zero means bit 3 is clear.
//

res = (x & (1u << 3)) != 0;


// ------------------------------------------------------------
// CHECK WHETHER A BIT IS CLEAR
//

res = (x & (1u << 2)) == 0;


// ------------------------------------------------------------
// CHECK WHETHER ALL BITS IN A MASK ARE SET
//
// Every masked bit must be 1.
//
//   10101100
// & 10100000
// ----------
//   10100000
//
// Compare result against the original mask.
//

mask = 0b10100000;
res = (x & mask) == mask;


// ------------------------------------------------------------
// CHECK WHETHER ANY BITS IN A MASK ARE SET
//
// At least one masked bit must be 1.
//

mask = 0b00001111;
res = (x & mask) != 0;



//
// ============================================================
// 3. COMBINING BITWISE OPERATIONS
// ============================================================
//


// ------------------------------------------------------------
// SET MULTIPLE BITS
//
// Set bits 0, 2, and 5 simultaneously.
//
//   10101100
// | 00100101
// ----------
//   10101101
//
// (1u << 0) | (1u << 2) | (1u << 5)
// Creates the combined mask.
//

mask = (1u << 0) | (1u << 2) | (1u << 5);
x |= mask;


// ------------------------------------------------------------
// CLEAR MULTIPLE BITS
//
// Clear bits 0, 2, and 5 simultaneously.
//
//   10101100
// & 11011010
// ----------
//   10001000
//
// AND with the inverted combined mask.
//

mask = (1u << 0) | (1u << 2) | (1u << 5);
x &= ~mask;


// ------------------------------------------------------------
// TOGGLE MULTIPLE BITS
//
// Flip bits 0, 2, and 5 simultaneously.
//
//   10101100
// ^ 00100101
// ----------
//   10001001
//

mask = (1u << 0) | (1u << 2) | (1u << 5);
x ^= mask;


// ------------------------------------------------------------
// SET ONE BIT AND CLEAR ANOTHER
//
// Set bit 1 and clear bit 3.
//
// First clear bit 3:
//
//   10101100
// & 11110111
// ----------
//   10100100
//
// Then set bit 1:
//
//   10100100
// | 00000010
// ----------
//   10100110
//

x = (x & ~(1u << 3)) | (1u << 1);


// ------------------------------------------------------------
// SET A BIT CONDITIONALLY
//
// Set bit 3 if condition is true.
// Otherwise, leave the original value unchanged.
//

bool condition = true;

x |= ((uint8_t)condition << 3);


// ------------------------------------------------------------
// CLEAR A BIT CONDITIONALLY
//
// Clear bit 3 if condition is true.
// Otherwise, leave the original value unchanged.
//

x &= ~((uint8_t)condition << 3);



//
// ============================================================
// 4. MASKS AND EXTRACTING BIT FIELDS
// ============================================================
//


// ------------------------------------------------------------
// CREATE A MASK OF N BITS
//
// For N = 4:
//
//   00000001 << 4 = 00010000
//   00010000 - 1  = 00001111
//
// Produces four consecutive 1 bits.
//

uint32_t bit_count = 4;
mask = (1u << bit_count) - 1;


// ------------------------------------------------------------
// EXTRACT THE LOWEST N BITS
//
//   10101100
// & 00001111
// ----------
//   00001100
//
// Keeps the lowest four bits.
//

res = x & 0b00001111;


// ------------------------------------------------------------
// EXTRACT BITS AT A POSITION
//
// Extract bits 2, 3, and 4.
//
// Original:
//
//   10101100
//
// Shift right by 2:
//
//   00101011
//
// Mask with 00000111:
//
//   00000111
// & 00001011
// ----------
//   00000011
//
// Result = 3.
//

res = (x >> 2) & 0b00000111;


// ------------------------------------------------------------
// CLEAR THE LOWEST N BITS
//
// Clear bits 0 through 3.
//
//   10101100
// & 11110000
// ----------
//   10100000
//

res = x & ~0b00001111;


// ------------------------------------------------------------
// EXTRACT THE HIGHEST N BITS OF AN 8-BIT VALUE
//
// Keep the upper four bits.
//
//   10101100
// & 11110000
// ----------
//   10100000
//
// Shift right to move them to the low positions:
//
//   00001010
//

res = (x & 0b11110000) >> 4;


// ------------------------------------------------------------
// INSERT A VALUE INTO A BIT FIELD
//
// Replace bits 2 and 3 with binary 10.
//
// Original:
//
//   10101100
//
// Clear bits 2 and 3:
//
//   10100011
//
// Shift the new value into position:
//
//   00001000
//
// OR them together:
//
//   10101011
//

uint32_t position = 2;
uint32_t field_mask = 0b11;
uint32_t value = 0b10;

x = (x & ~(field_mask << position)) |
    ((value & field_mask) << position);


// ------------------------------------------------------------
// REPLACE A FIELD WITHOUT AFFECTING OTHER BITS
//
// General pattern:
//
//   (original & ~field_mask) | new_field
//
// Useful for updating register fields.
//

uint32_t field = 0b101;
position = 3;
field_mask = 0b111;

res = (x & ~(field_mask << position)) |
      ((field & field_mask) << position);


// ------------------------------------------------------------
// COMPARE A FIELD AGAINST A VALUE
//
// Extract bits 2-4, then compare with binary 011.
//

res = ((x >> 2) & 0b111) == 0b011;



//
// ============================================================
// 5. COMMON BIT TRICKS
// ============================================================
//


// ------------------------------------------------------------
// CHECK IF A NUMBER IS ODD
//
// The lowest bit determines odd/even.
//
//   00001001
// & 00000001
// ----------
//   00000001
//
// If bit 0 is 1, number is odd.
//

res = n & 1u;


// ------------------------------------------------------------
// CHECK IF A NUMBER IS EVEN
//

res = (n & 1u) == 0;


// ------------------------------------------------------------
// CHECK IF A NUMBER IS A POWER OF TWO
//
// A power of two has exactly one set bit.
//
// Example: 8
//
//   00001000
// - 00000001
// ----------
//   00000111
//
// AND the original and result:
//
//   00001000
// & 00000111
// ----------
//   00000000
//
// If result is zero, there was exactly one set bit.
//
// Must exclude zero.
//

res = (n != 0) && ((n & (n - 1)) == 0);


// ------------------------------------------------------------
// CLEAR THE LOWEST SET BIT
//
// n = 12:
//
//   00001100
// - 00000001
// ----------
//   00001011
//
// AND:
//
//   00001100
// & 00001011
// ----------
//   00001000
//
// Removes the rightmost 1 bit.
//

n &= (n - 1);


// ------------------------------------------------------------
// ISOLATE THE LOWEST SET BIT
//
// n = 12:
//
//   00001100
//
// Two's complement -n:
//
//   11110100
//
// AND:
//
//   00001100
// & 11110100
// ----------
//   00000100
//
// Keeps only the rightmost 1 bit.
//
// Use unsigned arithmetic.
//

res = n & (0u - n);


// ------------------------------------------------------------
// ISOLATE THE LOWEST ZERO BIT
//
// n = 12:
//
//   00001100
// ~ 00001100
// ----------
//   11110011
//
// Lowest zero bit of n is isolated.
//

res = (~n) & (n + 1u);


// ------------------------------------------------------------
// TURN ON ALL BITS BELOW THE HIGHEST SET BIT
//
// Example:
//
//   00010000
//
// After spreading bits right:
//
//   00011111
//
// Useful for creating masks and finding powers of two.
//

uint32_t spread = n;
spread |= spread >> 1;
spread |= spread >> 2;
spread |= spread >> 4;
spread |= spread >> 8;
spread |= spread >> 16;


// ------------------------------------------------------------
// ROUND DOWN TO THE NEXT POWER-OF-TWO BOUNDARY
//
// Example: 13 -> 8
//
//   00001101
// & 11111000
// ----------
//   00001000
//
// This requires a power-of-two alignment.
//

uint32_t alignment = 8;
res = n & ~(alignment - 1u);


// ------------------------------------------------------------
// ROUND UP TO THE NEXT POWER-OF-TWO BOUNDARY
//
// Example: 13 -> 16
//
//   (13 + 8 - 1) & ~(8 - 1)
//
//   00010100
// & 11111000
// ----------
//   00010000
//
// Requires a power-of-two alignment.
// Check for overflow in production code.
//

res = (n + alignment - 1u) & ~(alignment - 1u);


// ------------------------------------------------------------
// CHECK WHETHER A NUMBER IS ALIGNED
//
// Address is aligned if its lowest alignment bits are zero.
//
// For alignment = 8:
//
//   00010000
// & 00000111
// ----------
//   00000000
//
// Zero means aligned.
//

res = (n & (alignment - 1u)) == 0;


// ------------------------------------------------------------
// GET OFFSET WITHIN AN ALIGNMENT BOUNDARY
//
// Example: address 13, alignment 8:
//
//   00001101
// & 00000111
// ----------
//   00000101
//
// Offset = 5.
//

res = n & (alignment - 1u);



//
// ============================================================
// 6. COUNTING AND COMPARING BITS
// ============================================================
//


// ------------------------------------------------------------
// COUNT SET BITS (BRIAN KERNIGHAN'S ALGORITHM)
//
// Each iteration removes one set bit.
//
// n = 12:
//
//   00001100
// & 00001011
// ----------
//   00001000
//
// Next iteration:
//
//   00001000
// & 00000111
// ----------
//   00000000
//
// Two iterations = two set bits.
//

uint32_t count = 0;
uint32_t temp = n;

while (temp != 0) {
    temp &= (temp - 1u);
    count++;
}


// ------------------------------------------------------------
// COUNT SET BITS (CHECK EVERY BIT)
//
// Shift right one bit at a time.
// Add the lowest bit to the count.
//

count = 0;
temp = n;

while (temp != 0) {
    count += temp & 1u;
    temp >>= 1;
}


// ------------------------------------------------------------
// XOR TO FIND DIFFERENCES BETWEEN TWO VALUES
//
//   10101100
// ^ 01010101
// ----------
//   11111001
//
// Every 1 represents a differing bit.
//

res = x ^ z;


// ------------------------------------------------------------
// HAMMING DISTANCE
//
// Count the number of differing bits.
//

temp = x ^ z;
count = 0;

while (temp != 0) {
    temp &= (temp - 1u);
    count++;
}


// ------------------------------------------------------------
// CHECK WHETHER TWO VALUES HAVE THE SAME BITS
//

res = (x ^ y) == 0;


// ------------------------------------------------------------
// CHECK WHETHER TWO VALUES DIFFER BY EXACTLY ONE BIT
//
// XOR and check whether the result is a power of two.
//

temp = x ^ y;

res = (temp != 0) && ((temp & (temp - 1u)) == 0);



//
// ============================================================
// 7. BITWISE ARITHMETIC
// ============================================================
//


// ------------------------------------------------------------
// ADD WITHOUT USING +
// 
// XOR calculates the sum without carry.
// AND followed by left shift calculates the carry.
//
// Example: 5 + 3
//
//   0101
// ^ 0011
// ------
//   0110     (sum without carry)
//
//   0101
// & 0011
// ------
//   0001
// <<    1
// ------
//   0010     (carry)
//
// Repeat until carry is zero.
//

uint32_t a = 5;
uint32_t b = 3;

while (b != 0) {
    uint32_t carry = (a & b) << 1;
    a ^= b;
    b = carry;
}

res = a;


// ------------------------------------------------------------
// MULTIPLY BY TWO
//
// Left shift by one.
//

res = n << 1;


// ------------------------------------------------------------
// MULTIPLY BY FOUR
//
// Left shift by two.
//

res = n << 2;


// ------------------------------------------------------------
// DIVIDE BY TWO (UNSIGNED)
//
// Right shift by one.
//

res = n >> 1;


// ------------------------------------------------------------
// MODULO BY A POWER OF TWO
//
// Example: 13 % 8 = 5
//
//   00001101
// & 00000111
// ----------
//   00000101
//
// Works because 8 is a power of two.
//

res = n & (8u - 1u);


// ------------------------------------------------------------
// SWAP TWO VALUES USING XOR
//
// This is an interview trick, not recommended in production.
// A temporary variable is clearer and avoids aliasing issues.
//

a = 5;
b = 3;

a ^= b;
b ^= a;
a ^= b;


// ------------------------------------------------------------
// NEGATE AN INTEGER USING TWO'S COMPLEMENT
//
// Invert all bits and add one.
//
//   00000101
// NOT
//   11111010
// +         1
// ----------
//   11111011
//
// For signed values, use care around INT_MIN.
// Unsigned arithmetic is well-defined modulo 2^N.
//

uint32_t unsigned_value = 5;
uint32_t negative_value = ~unsigned_value + 1u;



//
// ============================================================
// 8. ROTATIONS
// ============================================================
//


// ------------------------------------------------------------
// ROTATE LEFT
//
// Bits that leave the left side wrap around to the right.
//
// Example: rotate 8-bit 10101100 left by 2:
//
//   10101100
//   10110010
//
// General pattern:
//
//   (x << shift) | (x >> (width - shift))
//
// Avoid shifts equal to the type width.
// This helper handles shift == 0.
//

uint32_t rotate_left_32(uint32_t value, uint32_t shift)
{
    shift %= 32;

    if (shift == 0)
        return value;

    return (value << shift) | (value >> (32 - shift));
}


// ------------------------------------------------------------
// ROTATE RIGHT
//
// Bits that leave the right side wrap around to the left.
//

uint32_t rotate_right_32(uint32_t value, uint32_t shift)
{
    shift %= 32;

    if (shift == 0)
        return value;

    return (value >> shift) | (value << (32 - shift));
}



//
// ============================================================
// 9. SIGNED INTEGER BIT OPERATIONS
// ============================================================
//


// ------------------------------------------------------------
// CHECK SIGN BIT
//
// For a 32-bit unsigned representation:
//
//   10000000 ... = high bit set
//
// For signed integers, negative values typically have
// the most significant bit set on modern systems.
//
// Prefer comparing signed values directly with zero.
//

int signed_value = -5;

res = signed_value < 0;


// ------------------------------------------------------------
// EXTRACT SIGN BIT OF A 32-BIT VALUE
//
// Shift the most significant bit into position 0.
//

res = (uint32_t)signed_value >> 31;


// ------------------------------------------------------------
// ABSOLUTE VALUE USING BITWISE OPERATIONS
//
// This is a common two's-complement trick.
//
// Be careful: INT_MIN cannot be represented as a positive
// int, so this expression has signed-overflow problems
// for INT_MIN.
//
// Do not use this as a general replacement for abs().
//

int sign_mask = signed_value >> 31;
int absolute_value = (signed_value ^ sign_mask) - sign_mask;



//
// ============================================================
// 10. USEFUL LOW-LEVEL / SYSTEMS PROGRAMMING PATTERNS
// ============================================================
//


// ------------------------------------------------------------
// CHECK IF ALIGNMENT IS A POWER OF TWO
//
// Exactly one bit must be set.
//

res = (alignment != 0) &&
      ((alignment & (alignment - 1u)) == 0);


// ------------------------------------------------------------
// CLEAR ADDRESS OFFSET TO ALIGN DOWN
//
// Example: address = 0x1237, alignment = 16
//
//   0x1237 = ... 00110111
//   mask   = ... 11110000
//
// Result  = ... 00110000
//
// Common in allocators, memory managers, and page handling.
//

uintptr_t address = 0x1237;
uintptr_t aligned_down = address & ~(uintptr_t)(alignment - 1u);


// ------------------------------------------------------------
// ALIGN ADDRESS UP
//
// Example: address = 0x1237, alignment = 16
//
//   address + alignment - 1
//   0x1237 + 0xF = 0x1246
//
//   0x1246 & ~0xF = 0x1240
//
// Result: 0x1240
//
// Check for integer overflow before adding.
//

uintptr_t aligned_up =
    (address + alignment - 1u) & ~(uintptr_t)(alignment - 1u);


// ------------------------------------------------------------
// GET ADDRESS OFFSET
//
// Get the position within an alignment boundary.
//

uintptr_t offset = address & (alignment - 1u);


// ------------------------------------------------------------
// PACK MULTIPLE VALUES INTO ONE INTEGER
//
// Example: combine two 4-bit values.
//
//   high = 1010
//   low  = 0101
//
// Shift high left four bits:
//
//   10100000
//
// OR low into the lower four bits:
//
//   10100101
//

uint8_t high = 0b1010;
uint8_t low  = 0b0101;

uint8_t packed = (uint8_t)((high << 4) | (low & 0x0F));


// ------------------------------------------------------------
// UNPACK VALUES FROM AN INTEGER
//
// Extract the upper and lower nibbles.
//

high = (packed >> 4) & 0x0F;
low  = packed & 0x0F;


// ------------------------------------------------------------
// PACK THREE 8-BIT VALUES INTO A 24-BIT VALUE
//
//   AAAAAAAA BBBBBBBB CCCCCCCC
//
// Each value gets its own byte.
//

uint32_t red   = 0x12;
uint32_t green = 0x34;
uint32_t blue  = 0x56;

uint32_t rgb = (red << 16) | (green << 8) | blue;


// ------------------------------------------------------------
// EXTRACT RGB COMPONENTS
//

red   = (rgb >> 16) & 0xFF;
green = (rgb >> 8)  & 0xFF;
blue  = rgb & 0xFF;


// ------------------------------------------------------------
// CHECK FLAGS
//
// Flags are commonly combined using OR.
//

#define FLAG_READ    (1u << 0)
#define FLAG_WRITE   (1u << 1)
#define FLAG_EXECUTE (1u << 2)

uint32_t flags = FLAG_READ | FLAG_WRITE;


// Check if READ is enabled.
res = (flags & FLAG_READ) != 0;


// Enable EXECUTE.
flags |= FLAG_EXECUTE;


// Disable WRITE.
flags &= ~FLAG_WRITE;


// Toggle READ.
flags ^= FLAG_READ;


// Check whether BOTH READ and EXECUTE are enabled.
res = (flags & (FLAG_READ | FLAG_EXECUTE)) ==
      (FLAG_READ | FLAG_EXECUTE);


// ------------------------------------------------------------
// CHECK WHETHER FLAGS CONTAIN ANY OF A SET OF OPTIONS
//

res = (flags & (FLAG_READ | FLAG_WRITE)) != 0;


// ------------------------------------------------------------
// REMOVE ALL FLAGS IN A MASK
//

flags &= ~(FLAG_READ | FLAG_WRITE | FLAG_EXECUTE);


//
// ============================================================
// 11. USEFUL C-SPECIFIC BITWISE BUILTINS
// ============================================================
//


// ------------------------------------------------------------
// COUNT LEADING ZEROES
//
// GCC / Clang builtin.
// __builtin_clz(0) is undefined.
// Use a nonzero input.
//

uint32_t value = 8;
int leading_zeros = __builtin_clz(value);


// ------------------------------------------------------------
// COUNT TRAILING ZEROES
//
// GCC / Clang builtin.
// __builtin_ctz(0) is undefined.
//

int trailing_zeros = __builtin_ctz(value);


// ------------------------------------------------------------
// COUNT SET BITS
//
// GCC / Clang builtin.
//

int population_count = __builtin_popcount(value);


// ------------------------------------------------------------
// PARITY
//
// Returns 1 if an odd number of bits are set,
// 0 if an even number of bits are set.
//

int parity = __builtin_parity(value);


// ------------------------------------------------------------
// FIND THE POSITION OF THE HIGHEST SET BIT
//
// GCC / Clang builtin.
// __builtin_clz(0) is undefined.
//

int highest_bit_position = 31 - __builtin_clz(value);



//
// ============================================================
// 12. IMPORTANT RULES AND PITFALLS
// ============================================================
//


// 1. Use unsigned integers for bit manipulation.
//    uint8_t, uint16_t, uint32_t, uint64_t.
//
// 2. Bit positions start at zero from the RIGHT.
//
// 3. Always parenthesize bitwise expressions.
//
//    Correct:   (x & mask) == mask
//    Incorrect: x & mask == mask
//
// 4. Do not shift by the width of the type or more.
//
//    Bad:  1u << 32
//    Good: 1u << 31
//
// 5. Be careful with signed right shifts.
//    Right-shifting negative signed integers is
//    implementation-defined in C.
//
// 6. uint8_t and uint16_t are usually promoted to int
//    before arithmetic and bitwise operations.
//
// 7. Use 1u or UINT32_C(1) when constructing unsigned masks.
//
// 8. Validate alignment before using alignment - 1.
//
//    alignment must be nonzero and a power of two.
//
// 9. Check for overflow when adding sizes or addresses.
//
// 10. Bitwise operators are different from logical operators.
//
//     &  = bitwise AND
//     && = logical AND
//     |  = bitwise OR
//     || = logical OR
//
// 11. Do not use bitwise tricks when ordinary C is clearer.
//     For example, use x == 0 rather than obscure tricks.
//
// 12. For hardware registers, use the correct volatile access
//     and follow the platform's memory-ordering requirements.
//     volatile alone does not provide atomicity or synchronization.
//