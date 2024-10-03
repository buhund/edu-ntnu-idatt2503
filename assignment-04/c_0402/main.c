#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to escape (replace) &, < and > with &amp;, &lt; and &gt; respectively
char* escape_chars(char* input)
{
    size_t len = strlen(input);
    // Allocates memory/string length to account for the max length input
    // which is & --> &amp; which is 5 characters.
    // I.e. 1 * 5 = the max length of output, since &camp; is the longest conversion/output
    // Add + 1 to account for null terminator \0
    char* output = (char*)malloc(len * 5 + 1);
    char* current = output;

    while (*input)
    {
        if (*input == '&')
        {
            strcpy(current, "&amp;");
            current += 5;
        } else if (*input == '<')
        {
            strcpy(current, "&lt;");
            current += 4;
        } else if (*input == '>')
        {
            strcpy(current, "&gt;");
            current += 4;
        } else
        {
            *current++ = *input;
        }
        input++;
    }

    *current = '\0'; // Null Terminator T0000
    return output;
}


int main(void)
{
    const char* input = "Cricket & Smigg are crocs. They like to gape, like so <, "
                        "but when they see flamingos they turn, >, and gape the other way.";
    char* escaped = escape_chars(input);
    printf("Original: %s\n", input);
    printf("Escaped: %s\n", escaped);
    free(escaped); // Free up allocated memory
    return 0;
}
