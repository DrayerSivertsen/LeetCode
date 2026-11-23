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

/*

In this challenge, you will learn the usage of the for loop, which is a programming
language statement which allows code to be executed until a terminal condition is
met. They can even repeat forever if the terminal condition is never met.

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	for (int i = a; i < b + 1; i++) {
        if (i >=1 && i <= 9) {
            if (i == 1) {
                printf("one\n");
            } else if (i == 2) {
                printf("two\n");
            } else if (i == 3) {
                printf("three\n");
            } else if (i == 4) {
                printf("four\n");
            } else if (i == 5) {
                printf("five\n");
            } else if (i == 6) {
                printf("six\n");
            } else if (i == 7) {
                printf("seven\n");
            } else if (i == 8) {
                printf("eight\n");
            } else if (i == 9) {
                printf("nine\n");
            }

        } else {
            if (i % 2 == 0) {
                printf("even\n");
            } else {
                printf("odd\n");
            }
        }
    }

    return 0;
}

/*

Given a five digit integer, print the sum of its digits.

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
    int sum = 0;
    scanf("%d", &n);
    while (n > 0) {
        sum += (n % 10);
        n /= 10;
    }

    printf("%d\n", sum);

    return 0;
}

/*

In this challenge, you will use logical bitwise operators. 

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
    int and_max = 0;
    int and = 0;
    int or_max = 0;
    int or = 0;
    int xor_max = 0;
    int xor = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            and = i & j;
            if (and > and_max && and < k) {
                and_max = and;
            }
            
            or = i | j;
            if (or > or_max && or < k) {
                or_max = or;
            }
            
            xor = i ^ j;
            if (xor > xor_max && xor < k) {
                xor_max = xor;
            }
        }
    }
    
    printf("%d\n", and_max);
    printf("%d\n", or_max);
    printf("%d\n", xor_max);
  
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}

/*

Print a pattern of numbers from  to  as shown below. Each of the numbers is separated by a single space.

                            4 4 4 4 4 4 4  
                            4 3 3 3 3 3 4   
                            4 3 2 2 2 3 4   
                            4 3 2 1 2 3 4   
                            4 3 2 2 2 3 4   
                            4 3 3 3 3 3 4   
                            4 4 4 4 4 4 4   

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
    int size = 0;

    size = (n * 2) - 1;
    for (int i = 1; i < size + 1; i++) {
        for (int j = 1; j < size + 1; j++) {
            printf("%d ", ((int)fmax(abs(n - i), abs(n - j))) + 1);
        }
        
        printf("\n");
    }
    
    
    return 0;
}

/*

In this challenge, create an array of size  dynamically, and read the values
from stdin. Iterate the array calculating the sum of all elements. Print the
sum and free the memory where the array is stored.

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n = 0;
    int sum = 0;
    int *arr;

    scanf("%d", &n);
    scanf("\n");
    arr = (int*)malloc(sizeof(int) * n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    printf("%d\n", sum);
    
    return 0;
}

/*

Given an array, of size n, reverse it.

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    int j = 0;
    int k = 0;
    int tmp;
    
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }

    k = num - 1;
    while (j < k) {
        tmp = arr[j];
        arr[j] = arr[k];
        arr[k] = tmp;
        k--;
        j++;
    }


    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}

/*

Given a sentence, s, print each word of the sentence in a new line.

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    char *token;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    
    token = strtok(s, " ");
    while(token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
    
    return 0;
}

/*

Given a string, s, consisting of alphabets and digits, find the frequency of each digit in the given string.

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char *s;
    int i = 0;
    int arr[10] = { 0 };
    int num;
    
    s = (char*)malloc(sizeof(char) * 1000);
    memset(s, 0, 1000);
    scanf("%s", s);
    while (s[i] != '\0') {
        num = s[i] - '0';
        if (num >= 0 && num <= 9) {
            arr[num] += 1;
        }

        i++;
    }
    
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}

/*

Snow Howler is the librarian at the central library of the city of HuskyLand. He must handle requests which come in the following forms:

1 x y : Insert a book with  pages at the end of the  shelf.

2 x y : Print the number of pages in the  book on the  shelf.

3 x : Print the number of books on the  shelf.

*/

#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;

int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    total_number_of_books = calloc(total_number_of_shelves, sizeof(int));
    total_number_of_pages = malloc(sizeof(int*) * total_number_of_shelves);
    for (int i = 0; i < total_number_of_shelves; i++) {
        total_number_of_pages[i] = NULL;
    }
    
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);
    
    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            int x, y;
            int last_book;
            int *shelf;
            scanf("%d %d", &x, &y);
            last_book = *(total_number_of_books + x);
            shelf = *(total_number_of_pages + x);
            shelf = realloc(shelf, sizeof(int) * (last_book + 1));
            *(shelf + last_book) = y;
            *(total_number_of_pages + x) = shelf; // realloc could have moved pointer so save to original.
            *(total_number_of_books + x) += 1;

        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}

/*

This challenge will help you learn the concept of recursion.

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

int find_nth_term(int n, int a, int b, int c) {
    if (n == 1) {
        return a;
    } else if (n == 2) {
        return b;
    } else if (n == 3) {
        return c;
    } else {
        return find_nth_term(n - 1, a, b, c) + find_nth_term(n - 2, a, b, c) + find_nth_term(n - 3, a, b, c);
    }
}

int main() {
    int n, a, b, c;
  
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);
 
    printf("%d", ans); 
    return 0;
}

/*

Complete the function, marks_summation in the editor below.

marks_summation has the following parameters:

int marks[number_of_students]: the marks for each student
int number_of_students: the size of marks[]
char gender: either 'g' or 'b'

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Complete the following function.

int marks_summation(int* marks, int number_of_students, char gender) {
    int i = 0;
    int sum = 0;

    if (gender == 'g') {
        i = 1;
    }
    
    for (; i < number_of_students; i += 2) {
        sum += marks[i];
    }
    
    return sum;
}

int main() {
    int number_of_students;
    char gender;
    int sum;
  
    scanf("%d", &number_of_students);
    int *marks = (int *) malloc(number_of_students * sizeof (int));
 
    for (int student = 0; student < number_of_students; student++) {
        scanf("%d", (marks + student));
    }
    
    scanf(" %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);
    printf("%d", sum);
    free(marks);
 
    return 0;
}

/*

For every box from the input which has a height lesser than 41 feet, print its volume in a separate line.

*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_HEIGHT 41

struct box
{
	int length;
    int width;
    int height;
};

typedef struct box box;

int get_volume(box b) {
	return (b.length * b.width * b.height);
}

int is_lower_than_max_height(box b) {
	return b.height < 41;
}

int main()
{
	int n;
	scanf("%d", &n);
	box *boxes = malloc(n * sizeof(box));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &boxes[i].length, &boxes[i].width, &boxes[i].height);
	}
	for (int i = 0; i < n; i++) {
		if (is_lower_than_max_height(boxes[i])) {
			printf("%d\n", get_volume(boxes[i]));
		}
	}
	return 0;
}

/*

Given an array of strings sorted in lexicographical order, print all of its
permutations in strict lexicographical order. If two permutations look the
same, only print one of them.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
    // Step 1: Find the largest index k such that s[k] < s[k + 1]
    int k = -1;
    for (int i = 0; i < n - 1; i++) {
        if (strcmp(s[i], s[i + 1]) < 0) {
            k = i;
        }
    }
    if (k == -1) {
        return 0; // No next permutation
    }

    // Step 2: Find the largest index l greater than k such that s[k] < s[l]
    int l = -1;
    for (int i = k + 1; i < n; i++) {
        if (strcmp(s[k], s[i]) < 0) {
            l = i;
        }
    }

    // Step 3: Swap the value of s[k] with that of s[l]
    char *temp = s[k];
    s[k] = s[l];
    s[l] = temp;

    // Step 4: Reverse the sequence from s[k + 1] to s[n - 1]
    for (int i = k + 1, j = n - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    
    // strcmp(a, b) returns:
    // < 0 if a comes before b alphabetically
    // = 0 if a and b are equal
    // > 0 if a comes after b alphabetically

    return 1; // Next permutation exists
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
