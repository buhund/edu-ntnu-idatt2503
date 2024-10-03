#include <stdio.h>
#include <stdlib.h>
#include "escape.h"


int main(void)
{
    const char* input = "Cricket > & Smigg <";
    char* escaped = escape_chars(input);
    // printf("Original: %s\n", input);
    printf("%s\n", escaped);
    free(escaped); // Free up allocated memory
    return 0;
}
