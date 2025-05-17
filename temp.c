#include <stdio.h>

#define MAX 10

void main() {
    int a = 5, b = 10
    int arr[5] = {1, 2, 3, 4, 5;      // Error: missing closing brace and semicolon

    if(a > 10                     // Error: missing closing parenthesis
        printf("a is greater\n");  // Error: missing braces for if body

    else                          // Error: else without a matching if (because if is incomplete)
        printf("a is smaller\n")

    for(int i = 0 i < MAX; i++)   // Error: missing semicolon after initialization i=0
        printf("%d\n", i)         // Error: missing semicolon

    while b < 20 {                // Error: while needs parentheses: while (b < 20)
        b++;                     // correct line
    }                           

    switch(a) {                   // no error here, but adding errors inside switch
        case 5                    // Error: missing colon ':'
            printf("five\n");     
            break;               

        case 10:                  // correct
            printf("ten\n")       // Error: missing semicolon
            break;

        default:                  // correct
            printf("default\n");
    }                            // missing closing brace for main function (to be added after)
