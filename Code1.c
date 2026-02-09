#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char buffer[100];

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    /* Write to file */
    fp = fopen(argv[1], "w");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    printf("Enter text (Ctrl+D to stop):\n");
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        fputs(buffer, fp);
    }
    fclose(fp);

    /* Read from file */
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    printf("\nFile contents:\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    fclose(fp);
    return 0;
}
