#include <stdio.h>

int foo() {
    int x;
    x = y + 5;      // ERROR: 'y' used but not declared
    return;         // ERROR: function 'foo' expects an int return but no value returned
}

int main() {
    int x;
    int x;          // ERROR: redeclaration of variable 'x' in same scope
    x = 10;
    break;          // ERROR: 'break' outside loop
    return 0;
}
