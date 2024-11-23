#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"

int main() {
    // Testing all_letters
    printf("all_letters(\"Hello World\"): %d\n", all_letters("Hello World")); //  1
    printf("all_letters(\"He11o World\"): %d\n", all_letters("He11o World")); //  0

    puts("");

    // Testing num_in_range
    printf("num_in_range(\"abcdef\", 'b', 'e'): %d\n", num_in_range("abcdef", 'b', 'e')); //  4
    printf("num_in_range(\"Yellow\", 'f', 'm'): %d\n", num_in_range("Yellow", 'f', 'm')); //  2

    puts("");

    // Testing diff
    printf("diff(\"hello\", \"hello\"): %d\n", diff("hello", "hello"));  //  0
    printf("diff(\"hello\", \"hella\"): %d\n", diff("hello", "hella"));  //  1
    printf("diff(\"\", \"abcd\"): %d\n", diff("", "abcd"));  // Expected: 4
    printf("diff(\"abc\", \"\"): %d\n", diff("abc", ""));  // Expected: 3
    printf("diff(\"Book\", \"Back\"): %d\n", diff("Book", "Back"));  //  2

    puts("");
    
    // Testing shorten
    printf("shorten(\"Programming\", 7): ");
    shorten("Programming", 7); // Expected: "Program"
    puts("");

    printf("shorten(\"Data Structures\", 20): ");
    shorten("Data Structures", 20); // Expected: "Data Structures"
    puts("");

    printf("shorten(\"Hello World\", 5): ");
    shorten("Hello World", 5); // Expected: "Hello"
    puts("");

    printf("shorten(\"Hello World\", 20): ");
    shorten("Hello World", 20); // Expected: "Hello World"
    puts("");

    puts("");

    // Testing len_diff
    printf("len_diff(\"Philadelphia\", \"Hello\"): %d\n", len_diff("Philadelphia", "Hello")); // Expected: 7
    printf("len_diff(\"Program\", \"Code\"): %d\n", len_diff("Program", "Code")); // Expected: 3

    puts("");

    // Testing rm_left_space
    printf("rm_left_space(\"   Leading spaces\"): ");
    rm_left_space("   Leading spaces"); // Expected: "Leading spaces"
    puts("");

    printf("rm_left_space(\"No Leading Spaces\"): ");
    rm_left_space("No Leading Spaces"); // Expected: "No Leading Spaces"
    puts("");

    printf("rm_left_space(\"     Hello World\"): ");
    rm_left_space("     Hello World"); // Expected: "Hello World"
    puts("");

    printf("rm_left_space(\"     Hello\"): ");
    rm_left_space("     Hello"); // Expected: "Hello"
    puts("");

    puts("");

    // Testing rm_right_space
    printf("rm_right_space(\"Hello \"): ");
    rm_right_space("Hello "); // Expected: "Hello"
    puts("");

    printf("rm_right_space(\"Hello World   \"): ");
    rm_right_space("Hello World   "); // Expected: "Hello World"
    puts("");

    puts("");

    // Testing rm_space
    printf("rm_space(\" Hello \"): ");
    rm_space(" Hello "); // Expected: "Hello"
    puts("");

    printf("rm_space(\"  Trimmed  \"): ");
    rm_space("  Trimmed  "); // Expected: "Trimmed"
    puts("");

    puts("");

    return 0;
}
