#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** parse_args( char * line ) {
    char ** argz = malloc(6 * sizeof(char *));
    char * temp = NULL;
    int i = 0;
    while ((temp = strsep(&line, " "))) {
        argz[i] = temp;
        i++;
    }
    argz[i] = NULL;
    return argz;
}

int main() {
    /* char line[100] = "wow-this-is-cool";
    char *s1 = line;
    printf("[%s]\n", strsep( &s1, "-" ));
    printf("[%s]\n", s1); */
    char line[] = "ls -a -l";
    char ** args = parse_args( line );
    execvp(args[0], args);
    return 0;
}