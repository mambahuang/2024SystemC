/* This is the code written by myself. */
/* "Hello World" version 2 */

# include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Hello World!\n");
    // Please add your loop here
    for (int i = 1; i < argc; i++) {
        printf("%s ", argv[i]);
    }
    printf("\n");
    return(0);
}