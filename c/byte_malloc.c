
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

void*
aligned_malloc(size_t size, size_t alignment) {
    void *ptr;
    uintptr_t address;
    uintptr_t aligned_address;
    void **metadata;

    // Alignment must be a power of two.
    if (alignment == 0 || (alignment & (alignment - 1)) != 0) {
        return NULL;
    }

    // Ensure alignment is sufficient for metadata.
    if (alignment < _Alignof(void*)) {
        return NULL;
    }

    // Prevent allocation-size overflow.
    if (size > SIZE_MAX - (alignment - 1) - sizeof(void*)) {
        return NULL;
    }

    ptr = malloc(size + (alignment - 1) + sizeof(void*));

    if (ptr == NULL) {
        return NULL;
    }

    address = (uintptr_t)ptr + sizeof(void*);

    // Round address up to the next aligned address.
    aligned_address = (address + alignment - 1) & ~(uintptr_t)(alignment - 1);

    // Store original malloc pointer immediately before aligned pointer.
    metadata = (void**)(aligned_address - sizeof(void*));
    *metadata = ptr;

    return (void*)aligned_address;
}

void
aligned_free(void* ptr) {
    if (ptr == NULL) {
        return;
    }

    void **metadata = (void**)((uintptr_t)ptr - sizeof(void*));

    free(*metadata);
}

int
main(void) {

    // Test 1: 16-byte alignment.
    size_t alignment = 16;
    size_t size = 100;

    void *ptr = aligned_malloc(size, alignment);

    if (ptr == NULL) {
        printf("Test 1: Allocation failed\n");
        return 1;
    }

    printf("Test 1: 16-byte alignment\n");
    printf("Address: %p\n", ptr);
    printf("Aligned: %s\n",
           ((uintptr_t)ptr % alignment == 0) ? "YES" : "NO");

    aligned_free(ptr);


    // Test 2: 64-byte alignment.
    alignment = 64;
    size = 256;

    ptr = aligned_malloc(size, alignment);

    if (ptr == NULL) {
        printf("Test 2: Allocation failed\n");
        return 1;
    }

    printf("\nTest 2: 64-byte alignment\n");
    printf("Address: %p\n", ptr);
    printf("Aligned: %s\n",
           ((uintptr_t)ptr % alignment == 0) ? "YES" : "NO");

    aligned_free(ptr);


    // Test 3: Write and read allocated memory.
    alignment = 128;
    size = 1024;

    ptr = aligned_malloc(size, alignment);

    if (ptr == NULL) {
        printf("Test 3: Allocation failed\n");
        return 1;
    }

    printf("\nTest 3: Memory read/write\n");

    unsigned char *buffer = (unsigned char*)ptr;

    for (size_t i = 0; i < size; i++) {
        buffer[i] = (unsigned char)(i % 256);
    }

    int passed = 1;

    for (size_t i = 0; i < size; i++) {
        if (buffer[i] != (unsigned char)(i % 256)) {
            passed = 0;
            break;
        }
    }

    printf("Read/write: %s\n", passed ? "PASSED" : "FAILED");

    aligned_free(ptr);


    // Test 4: Invalid alignment.
    ptr = aligned_malloc(100, 3);

    printf("\nTest 4: Invalid alignment\n");
    printf("Returned NULL: %s\n", ptr == NULL ? "YES" : "NO");


    // Test 5: Zero-size allocation.
    ptr = aligned_malloc(0, 64);

    printf("\nTest 5: Zero-size allocation\n");
    printf("Allocation: %s\n", ptr != NULL ? "SUCCESS" : "FAILED");

    aligned_free(ptr);


    // Test 6: NULL free.
    printf("\nTest 6: NULL free\n");
    aligned_free(NULL);
    printf("No crash: PASSED\n");

    return 0;
}
