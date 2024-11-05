#include <stdlib.h>
#include <string.h>
#include "escape.h"

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

    *current = '\0';
    return output;
}
