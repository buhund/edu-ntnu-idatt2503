#include <stdio.h>

void platypus() {
    printf("Gosh darn it! The flag is: FLAG{PICKLED_SAUSAGE_SANDWICH}\n");
}

void circle() {
    char buffer[50];
    printf("Enter your input: ");
    gets(buffer);
    printf("You entered: %s\n", buffer);
}

int main() {
    printf("Welcome to some CTF!\n");
    circle();
    return 0;
}