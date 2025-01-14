#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    puts("START----------------");
    printf("\n");
    puts("1.");
    // Testing all_letters
    printf("all_letters(\"Hello World\"): %d\n", all_letters("Hello World")); //  1
    printf("all_letters(\"He11o World\"): %d\n", all_letters("He11o World")); //  0

    puts("");
    printf("\n");
    
    puts("2.");
    // Testing num_in_range 
    printf("num_in_range(\"abcdef\", 'b', 'e'): %d\n", num_in_range("abcdef", 'b', 'e')); //  4
    printf("num_in_range(\"Yellow\", 'f', 'm'): %d\n", num_in_range("Yellow", 'f', 'm')); //  2

    puts("");
    printf("\n");

    puts("3.");
    // Testing diff
    printf("diff(\"hello\", \"hello\"): %d\n", diff("hello", "hello"));  //  0
    printf("diff(\"hello\", \"hella\"): %d\n", diff("hello", "hella"));  //  1
    printf("diff(\"\", \"abcd\"): %d\n", diff("", "abcd"));  // Expected: 4
    printf("diff(\"abc\", \"\"): %d\n", diff("abc", ""));  // Expected: 3
    printf("diff(\"Book\", \"Back\"): %d\n", diff("Book", "Back"));  //  2

    puts("");
    printf("\n");
    
    puts("4.");
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
    printf("\n");

    puts("5.");
    // Testing len_diff
    printf("len_diff(\"Philadelphia\", \"Hello\"): %d\n", len_diff("Philadelphia", "Hello")); // Expected: 7
    printf("len_diff(\"Program\", \"Code\"): %d\n", len_diff("Program", "Code")); // Expected: 3

    puts("");
    printf("\n");

    puts("6.");
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
    printf("\n");

    puts("7.");
    // Testing rm_right_space
    printf("rm_right_space(\"Hello \"): ");
    rm_right_space("Hello "); // Expected: "Hello"
    puts("");

    printf("rm_right_space(\"Hello World   \"): ");
    rm_right_space("Hello World   "); // Expected: "Hello World"
    puts("");

    puts("");
    printf("\n");
    
    puts("8.");
    // Testing rm_space
    printf("rm_space(\" Hello \"): ");
    rm_space(" Hello "); // Expected: "Hello"
    puts("");

    printf("rm_space(\"  Trimmed  \"): ");
    rm_space("  Trimmed  "); // Expected: "Trimmed"
    puts("");

    puts("");
    printf("\n");

    puts("9.");
    // Testing find
    printf("find(\"Hello\", \"l\"): %d\n", find("Hello", "l")); // Expected: 2
    printf("find(\"Hello\", \"q\"): %d\n", find("Hello", "q")); // Expected: -1
    printf("find(\"Mississippi\", \"iss\"): %d\n", find("Mississippi", "iss")); // Expected: 1

    puts("");
    printf("\n");

    puts("10.");
    // Testing ptr_to
    char *result = ptr_to("Hello", "l");
    printf("ptr_to(\"Hello\", \"l\"): %s\n", result ? result : "NULL"); // Expected: "llo"
    
    result = ptr_to("Hello", "q");
    printf("ptr_to(\"Hello\", \"q\"): %s\n", result ? result : "NULL"); // Expected: NULL

    puts("");
    printf("\n");

    puts("11.");
    // Testing is_empty
    printf("is_empty(\" \"): %d\n", is_empty(" "));  // Expected: 1 (Only whitespace)
    printf("is_empty(\"Hello\"): %d\n", is_empty("Hello"));  // Expected: 0 (Non-empty string)
    printf("is_empty(NULL): %d\n", is_empty(NULL));  // Expected: 1 (NULL string)

    puts("");
    printf("\n");

    puts("12.");
    // Testing str_zip
    printf("str_zip(\"Temple\", \"Hello\"): %s\n", str_zip("Temple", "Hello")); // Expected: "THeemlplloe"
    printf("str_zip(\"Spongebob\", \"Patrick\"): %s\n", str_zip("Spongebob", "Patrick")); // Expected: "SPpaotnrgiecbkob"
    printf("str_zip(\"abc\", \"123\"): %s\n", str_zip("abc", "123")); // Expected: "a1b2c3"

    puts("");
    printf("\n");

    puts("13.");
    // Testing capitalize
    printf("capitalize(\"hello world\"): ");
    capitalize("hello world"); // Expected: "Hello World"
    puts("");

    printf("capitalize(\"sky\"): ");
    capitalize("sky"); // Expected: "Sky"
    puts(""); 

    printf("capitalize(\"gOoD mOrNiNg tO yOu\"): ");
    capitalize("gOoD mOrNiNg tO yOu"); // Expected: "Good Morning To You"
    puts(""); 

    printf("capitalize(\"mY nAmE\"): ");
    capitalize("mY nAmE"); // Expected: "My Name"
    puts(""); 

    puts(""); 
    printf("\n");

    puts("14.");
    // Testing strcmp_ign_case
    printf("strcmp_ign_case(\"hello\", \"goodbye\"): %d\n", strcmp_ign_case("hello", "goodbye")); // Expected: positive (e.g., 1)
    printf("strcmp_ign_case(\"Hello\", \"hello\"): %d\n", strcmp_ign_case("Hello", "hello"));     // Expected: 0
    printf("strcmp_ign_case(\"apple\", \"zebra\"): %d\n", strcmp_ign_case("apple", "zebra"));     // Expected: negative (e.g., -1)

    puts("");
    printf("\n");

    puts("15.");
    // Testing take_last
    char test1[] = "hello"; 
    char test2[] = "hello";
    char test3[] = "world";
    char test4[] = "Brubeck";
    take_last(test1, 3);
    printf("take_last(\"hello\", 3): %s\n", test1); // Expected: "llo"
    take_last(test2, 6);
    printf("take_last(\"hello\", 6): %s\n", test2); // Expected: "hello"
    take_last(test3, 2);
    printf("take_last(\"world\", 2): %s\n", test3); // Expected: "ld"
    take_last(test4, 5);
    printf("take_last(\"Brubeck\", 5): %s\n", test4); // Expected: "ubeck"

    puts("");
    printf("\n");

    puts("16.");
    // Testing dedup
    char *ded1 = dedup("hello");
    printf("dedup(\"hello\"): %s\n", ded1); // Expected: "helo"
    free(ded1);

    char *ded2 = dedup("There's always money in the banana stand.");
    printf("dedup(\"There's always money in the banana stand.\"): %s\n", ded2); // Expected: "Ther's alwymonitbd."
    free(ded2);

    char *ded3 = dedup("aabbccdd");
    printf("dedup(\"aabbccdd\"): %s\n", ded3); // Expected: "abcd"
    free(ded3);

    puts("");
    printf("\n");

    puts("17.");
    // Testing pad
    char *padded1 = pad("hello", 6);
    printf("pad(\"hello\", 6): \"%s\"\n", padded1); // Expected: "hello "
    free(padded1);

    char *padded2 = pad("hello", 5);
    printf("pad(\"hello\", 5): \"%s\"\n", padded2); // Expected: "hello"
    free(padded2);

    char *padded3 = pad("world", 10);
    printf("pad(\"world\", 10): \"%s\"\n", padded3); // Expected: "world     "
    free(padded3);

    char *padded4 = pad("pad", 2);
    printf("pad(\"pad\", 2): \"%s\"\n", padded4); // Expected: "pad"
    free(padded4);

    puts("");
    printf("\n");

    puts("18.");
    // Testing ends_with_ignore_case
    printf("ends_with_ignore_case(\"Coding\", \"ing\"): %d\n", ends_with_ignore_case("Coding", "ing")); // Expected: 1
    printf("ends_with_ignore_case(\"Coding\", \"ed\"): %d\n", ends_with_ignore_case("Coding", "ed"));   // Expected: 0
    printf("ends_with_ignore_case(\"ELON MUSK\", \"sk\"): %d\n", ends_with_ignore_case("ELON MUSK", "sk")); // Expected: 1

    puts("");
    printf("\n");

    puts("19.");
    // Testing repeat
    char *repeat1 = repeat("hello", 3, '-');
    printf("repeat(\"hello\", 3, '-'): %s\n", repeat1);  // Expected: "hello-hello-hello"
    free(repeat1);

    char *repeat2 = repeat("all right", 2, ',');
    printf("repeat(\"all right\", 2, ','): %s\n", repeat2);  // Expected: "all right,all right"
    free(repeat2);

    char *repeat3 = repeat("test", 4, ' ');
    printf("repeat(\"test\", 4, ' '): %s\n", repeat3);  // Expected: "test test test test"
    free(repeat3);

    puts("");
    printf("\n");

    puts("20.");
    // Testing replace
    char *replace1 = replace("Steph is the X", "X", "best");
    printf("replace(\"Steph is the X\", \"X\", \"best\"): %s\n", replace1); // Expected: "Steph is the best"
    free(replace1); 

    char *replace2 = replace("NBA X rocks X", "X", "game");
    printf("replace(\"NBA X rocks X\", \"X\", \"game\"): %s\n", replace2); // Expected: "NBA game rocks game"
    free(replace2); 

    char *replace3 = replace("I love coding and coding is fun", "coding", "code");
    printf("replace(\"I love coding and coding is fun\", \"coding\", \"code\"): %s\n", replace3); // Expected: "I love code and code is fun"
    free(replace3);

    char *replace4 = replace("Life is great", "is", "awesome");
    printf("replace(\"Life is great\", \"is\", \"awesome\"): %s\n", replace4); // Expected: "Life awesome great"
    free(replace4);

    puts("");
    printf("\n");

    puts("21.");
    // Testing str_connect
    char *str_connect1 = str_connect((char *[]){"Hello", "world", "Hello", "world"}, 4, '-');
    printf("str_connect({\"Hello\", \"world\", \"Hello\", \"world\"}, 4, '-'): %s\n", str_connect1); // Expected: "Hello-world-Hello-world"
    free(str_connect1);

    char *str_connect2 = str_connect((char *[]){"Washington", "Adams", "Jefferson"}, 3, '+');
    printf("str_connect({\"Washington\", \"Adams\", \"Jefferson\"}, 3, '+'): %s\n", str_connect2); // Expected: "Washington+Adams+Jefferson"
    free(str_connect2);

    char *str_connect3 = str_connect((char *[]){"Apple", "Banana", "Cherry", "Date", "Elderberry", "Fig"}, 3, ',');
    printf("str_connect({\"Apple\", \"Banana\", \"Cherry\", \"Date\", \"Elderberry\", \"Fig\"}, 3, ','): %s\n", str_connect3); // Expected: "Apple,Banana,Cherry"
    free(str_connect3);

    puts("");
    printf("\n");

    puts("22.");
    // Testing rm_empties
    char *rm_empties1[] = {"Hello", "World", "", "", "Steph", NULL};
    printf("rm_empties({\"Hello\", \"World\", \"\", \"\", \"Steph\"}): ");
    rm_empties(rm_empties1);
    puts("");

    char *rm_empties2[] = {"One", "", "Two", "", "", "Three", NULL};
    printf("rm_empties({\"One\", \"\", \"Two\", \"\", \"\", \"Three\"}): ");
    rm_empties(rm_empties2);
    puts("");

    char *rm_empties3[] = {"", "Alpha", "Beta", "", "", "Gamma", NULL};
    printf("rm_empties({\"\", \"Alpha\", \"Beta\", \"\", \"\", \"Gamma\"}): ");
    rm_empties(rm_empties3);
    puts("");

    puts("");
    printf("\n");

    puts("23.");
    // Testing str_chop_all
    char **str_chop_all1 = str_chop_all("Hello/world/hello/world", '/');
    printf("str_chop_all(\"Hello/world/hello/world\", '/'): ");
    for (int i = 0; str_chop_all1[i] != NULL; i++) {
        printf("%s ", str_chop_all1[i]);
    }
    free(str_chop_all1);
    puts("");

    char **str_chop_all2 = str_chop_all("I am ready for a nice vacation", ' ');
    printf("str_chop_all(\"I am ready for a nice vacation\", ' '): ");
    for (int i = 0; str_chop_all2[i] != NULL; i++) {
        printf("%s ", str_chop_all2[i]);
    }
    free(str_chop_all2);
    puts("");

    char **str_chop_all3 = str_chop_all("Split.this.string.into.tokens", '.');
    printf("str_chop_all(\"Split.this.string.into.tokens\", '.'): ");
    for (int i = 0; str_chop_all3[i] != NULL; i++) {
        printf("%s ", str_chop_all3[i]);
    }
    free(str_chop_all3);
    puts("");

    printf("\n");
    puts("FIN----------------");

    return 0;
}
