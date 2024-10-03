#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "main.h" // Header-fil som inneholder prototype for escape_chars

// Fuzzer entry point
int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
    // Konverter fuzz-data til en C-streng
    char* input = (char*)malloc(size + 1);
    if (!input) return 0;

    memcpy(input, data, size);
    input[size] = '\0'; // Null-terminer streng

    // Kall escape_chars med fuzz-dataene
    char* result = escape_chars(input);

    // Frigi allokert minne
    free(result);
    free(input);

    return 0; // Ingen crash = test bestått
}
