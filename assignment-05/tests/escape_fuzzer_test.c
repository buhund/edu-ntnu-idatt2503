// tests/escape_fuzzer_test.c

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "../escape.h"

int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
    char* input = (char*)malloc(size + 1);
    if (!input) return 0;

    memcpy(input, data, size);
    input[size] = '\0'; // Nullterminate input

    // Kjøre escape_chars med fuzzer input-data
    char* result = escape_chars(input);

    free(result);
    free(input);

    return 0; // Returnerer null kræsj!
}
