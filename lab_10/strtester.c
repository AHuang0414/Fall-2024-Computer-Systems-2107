#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"

int main() {
    // Testing all_letters
    printf("all_letters(\"Hello World\"): %d\n", all_letters("Hello World")); //  1
    printf("all_letters(\"He11o World\"): %d\n", all_letters("He11o World")); //  0

    // Testing num_in_range
    printf("num_in_range(\"abcdef\", 'b', 'e'): %d\n", num_in_range("abcdef", 'b', 'e')); //  4
    printf("num_in_range(\"Yellow\", 'f', 'm'): %d\n", num_in_range("Yellow", 'f', 'm')); //  2

    // Testing diff
    printf("diff(\"hello\", \"hello\"): %d\n", diff("hello", "hello"));  //  0
    printf("diff(\"hello\", \"hella\"): %d\n", diff("hello", "hella"));  //  1
    printf("diff(\"hello\", \"hellooo\"): %d\n", diff("hello", "hellooo"));  //  2


    return 0;
}
