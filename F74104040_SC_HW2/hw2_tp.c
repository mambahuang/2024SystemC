#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void analyze_file(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file when analyzing file.\n");
        return;
    }

    int lines = 0, words = 0, chars = 0, upper_case = 0;
    int in_word = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        // Count lines
        if (ch == '\n') {
            lines++;
        }

        // Count alphanumeric characters
        if (isalnum(ch)) {
            chars++;
        }

        // Count uppercase letters
        if (isupper(ch)) {
            upper_case++;
        }

        // Count words
        if (isspace(ch)) {
            if (in_word) {
                in_word = 0;
                words++;
            }
        } else {
            in_word = 1;
        }
    }

    // Account for EOF line and the last word
    lines++;
    if (in_word) {
        words++;
    }

    printf("Lines: %d\n", lines);
    printf("Alphanumeric characters: %d\n", chars);
    printf("Uppercase letters: %d\n", upper_case);
    printf("Words: %d\n", words);

    fclose(file);
}

void convert_to_upper(const char* input_filename, const char* output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening files when converting to upper.\n");
        return;
    }

    char ch;
    while ((ch = fgetc(input_file)) != EOF) {
        fputc(toupper(ch), output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    // if (argc != 2) {
    //     printf("Usage: %s <input_file>\n", argv[0]);
    //     return 1;
    // }

    analyze_file(argv[1]);
    convert_to_upper(argv[1], "UPPER");

    return 0;
}
