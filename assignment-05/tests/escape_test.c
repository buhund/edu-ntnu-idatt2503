// tests/escape_test.c

#include "../escape.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Test 1: Ingen spesialtegn
    const char* input1 = "Hello Word";
    char* result1 = escape_chars(input1);
    assert(strcmp(result1, "Hello Word") == 0);
    free(result1);

    // Test 2: "&" skal bli til "&amp;"
    const char* input2 = "Donald Duck & Co";
    char* result2 = escape_chars(input2);
    assert(strcmp(result2, "Donald Duck &amp; Co") == 0);
    free(result2);

    // Test 3: "<" skal bli til "&lt;"
    const char* input3 = "5 < 10";
    char* result3 = escape_chars(input3);
    assert(strcmp(result3, "5 &lt; 10") == 0);
    free(result3);

    // Test 4: ">" skal bli til "&gt;"
    const char* input4 = "10 > 5";
    char* result4 = escape_chars(input4);
    assert(strcmp(result4, "10 &gt; 5") == 0);
    free(result4);

    // Test 5: Kombinasjon av alle spesialtegnene
    const char* input5 = "5 < 10 & 10 > 5";
    char* result5 = escape_chars(input5);
    assert(strcmp(result5, "5 &lt; 10 &amp; 10 &gt; 5") == 0);
    free(result5);

    printf("Green accross the board!!!\n");
    return 0;
}
