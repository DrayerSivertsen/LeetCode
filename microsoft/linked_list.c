#include <stdio.h>
#include <stdlib.h>





int main(void)
{
    int number = 5;

    int* pNum = &number;

    printf("Enter a number: ");
    scanf("%d", pNum);
    printf("input: %d\n", *pNum);


    return 0;
}