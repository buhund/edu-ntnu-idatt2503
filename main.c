#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h" // Inkluderer header-filen som inneholder escape_chars deklarasjonen

char* escape_chars(const char* input)
{
    size_t len = strlen(input);
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

    *current = '\0'; // Null-terminator
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
