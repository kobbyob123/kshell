#include <stdio.h>
#include <stdlib.h>

int main() {
    char *line = NULL;
    size_t len = 0;
    size_t read;

    printf("Enter text: ");
    // Read from standard input
    read = getline(&line, &len, stdin);

    if (read != -1) {
        printf("You entered: %s", line); // Includes newline
        printf("Exit code %ld\n", read);
    }

    free(line); // Always free the allocated memory
    return 0;
}
