/*

This challenge requires you to print  on a single line, and then print the already provided input string to stdout.

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	
    char s[100];

    scanf("%[^\n]%*c", &s);

    printf("Hello, World!\n");
    printf("%s\n", s);    
    return 0;
}

/*

This challenge will help you to learn how to take a character, a string and a sentence as input in C.

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    char ch;
    char s[100];
    char line[100];

    scanf("%c", &ch);
    scanf("\n");
    scanf("%s", s);
    scanf("\n");
    scanf("%99[^\n]%*c", line);
    
    printf("%c\n", ch);
    printf("%s\n", s);
    printf("%s\n", line);
    
    return 0;
}

/*

In this challenge, you will learn simple usage of functions in C.

*/

#include <stdio.h>

int max_of_four(int a, int b, int c, int d) {
    int max_val;
    
    if (a > b) {
        max_val = a;
    } else {
        max_val = b;
    }
    
    if (max_val < c) {
        max_val = c;
    }
    
    if (max_val < d) {
        max_val = d;
    }
    
    return max_val;
}


int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}

/*

In this challenge, you will learn to implement the basic functionalities of pointers in C.

*/

#include <stdio.h>

void update(int *a,int *b) {
    int res = 0;
    res = *a + *b;
    *b = *a - *b;
    if (*b < 0) {
        *b *= -1;
    }
    
    *a = res;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

/*

Given a positive integer denoting , do the following:

If , print the lowercase English word corresponding to the number (e.g., one for , two for , etc.).
If , print Greater than 9.

*/

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();



int main()
{
    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    if (1 <= n && n <= 9) {
        if (n == 1) {
            printf("one\n");
        } else if (n == 2) {
            printf("two\n");
        } else if (n == 3) {
            printf("three\n");
        } else if (n == 4) {
            printf("four\n");
        } else if (n == 5) {
            printf("five\n");
        } else if (n == 6) {
            printf("six\n");
        } else if (n == 7) {
            printf("seven\n");
        } else if (n == 8) {
            printf("eight\n");
        } else if (n == 9) {
            printf("nine\n");
        }

    } else if (n > 9) {

        printf("Greater than 9\n");
    }

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

/*

Your task is to take two numbers of int data type, two numbers of float data type as input and output their sum and difference.

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	
    int int1;
    int int2;
    float float1;
    float float2;
    
    scanf("%d", &int1);
    scanf("%d", &int2);
    scanf("\n");
    scanf("%f", &float1);
    scanf("%f", &float2);
    
    // printf("%.5d\n", n); // Output: 00042
    // printf("%08d\n", n); // Output: 00000042
    // printf("%10.3f\n", f); // Output:      3.142 (10-character width, 3 decimals)
    
    printf("%d ", int1 + int2);
    printf("%d\n", int1 - int2);
    printf("%.1f ", float1 + float2);
    printf("%.1f\n", float1 - float2);
    return 0;
}