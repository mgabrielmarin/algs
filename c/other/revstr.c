/* Reverse a string from stdout */
#include <stdio.h>
#include <stdlib.h>

void swap(char *i, char *j) {
    char tmp = *i;
    *i = *j;
    *j = tmp;
}

/* reverse whole line */
void revline(char *line, ssize_t linelen) {
    int i = 0;
    int j = linelen - 2; /* NOTE: skip '\n' and '\0' */
    while (i < j) {
        swap(&line[i], &line[j]);
        i++; j--;
    }
}

void revstr(char *str, ssize_t len) {
    int i = 0;
    int j = len;
    while (i < j) {
        swap(&str[i], &str[j]);
        i++; j--;
    }
}

/* reverse words in line 'line' with the size 'linelen' */
void revlinewords(char *line, ssize_t linelen) {
    int i = 0;
    int j = linelen - 2; /* NOTE: skip '\n' and '\0' */
    while (i < j) {
        int k = 0;
        while (line[k] != ' ' && line[k] != '\n' && line[k] != '\0') {
            k++;
        }
        revstr(line, k-1); /* remove ' ' or '\n' or '\0' */
        line += k+1; /* go to next word */
        i += k; /* iterate over line */
    }
}

int main(void) {
    char *line = NULL;
    size_t linecap = 0;
    ssize_t linelen;

    while ((linelen = getline(&line, &linecap, stdin)) > 0) {
        revlinewords(line, linelen);
        fwrite(line, linelen, 1, stdout);
    }

    return 0;
}
