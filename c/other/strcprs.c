/* Copyright (C) 2025 Mihai Gabriel Marin
 *
 * Take a string from stdin and try to compress it. For example if we have
 * 'aaabbc' the compressed result would be 'a3b2c'. If the compressed string
 * is smaller than the initial string return in, else return the initial one.
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    char *s = argv[1];
    char r[strlen(s)];
    char *pr = r;
    int i = 0, j = 1;
    int count = 1;
    while(*(s+i)) {
        if (*(s+i) == *(s+j)) {
            count++;
        } else {
            if (count > 1) {
                sprintf(pr, "%c%d", *(s+i), count);
                pr += 2;
                // If count has 2 or more  digits, iterate
                // result pointer by the number of digits
                while(count/=10) pr += 1;
            } else {
                sprintf(pr, "%c", *(s+i));
                pr += 1;
            }
            count = 1; // reset counter
        }
        i++; j++;
    }
    s = argv[1]; // restore s to initial position
    if (strlen(r) < strlen(s)) {
        printf("%s\n", r);
    } else {
        printf("%s\n", s);
    }
    return 0;
}
