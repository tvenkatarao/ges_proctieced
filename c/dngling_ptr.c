#include <stdlib.h> /* malloc, free, NULL */
#include <stdio.h> /*  puts, fprintf, stderr */

int main(void) {
    /* Let's allocate a string. */
    char *str = (char*) malloc( sizeof(char) * 4);


    /* Check to make sure that we got the allocated memory. */
    if (str == NULL) {
        fprintf(stderr, "Unable to allocate enough memory for str!\n");
        return -1;
    }

    /* Put "Hi!", in the string */
    *str = 'H';
    *(str+1) = 'i';
    *(str+2) = '!';
    *(str+3) = '\0';

    /* Print the string. */
    puts(str);

    /* We have no more use for str, we better free it. */
    free(str);

    /* Trying to print the string again will cause undefined behavior! */
    puts(str);

    /* Everything went fine! Note: The program will likely crash before
       this return actually sends that signal back to whatever executed it. */
    return 0;
}
