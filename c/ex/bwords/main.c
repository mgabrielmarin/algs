// Remove all banned words found in './banned.txt' from the file
// './to_redact.txt' and write the new output to './redacted.txt'.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE 80
#define NLINES 4
#define MAX_WORD 10
#define NWORDS 4

void afree(char **arr);
void aprint(char **arr);
char **rwords(char *fpath);
char *tword(char *w);

// Read words and store them to array of strings for latter use.
char **rwords(char *fpath) {
	FILE *f= fopen(fpath, "r");
	if (f == NULL) return NULL;
    int nl = NLINES;
	char **lines = malloc(sizeof(char*)*nl);
	char buf[MAX_LINE];
	int i = 0;
	while(fgets(buf, MAX_LINE, f)) {
        if (i > nl-1) {
            nl *= 2;
            lines = realloc(lines,sizeof(char*)*nl);
        }
		lines[i] = malloc(sizeof(char)*strlen(buf)+1);
		strncpy(lines[i], buf, strlen(buf));
		lines[i][strlen(buf)+1] = 0;
		i++;
	}
    int nw = NWORDS;
    char **words = malloc(sizeof(char*)*nw);
    char *w;
    i = 0;
    for (int j = 0; lines[j]; ++j) {
        while((w = strsep(&(lines[j]), " ")) != NULL) {
            if (i > nw - 1) {
                nw *= 2;
                words = realloc(words, sizeof(char*)*nw);
            }
            if (w[strlen(w)-1] == '\n') {
                w[strlen(w)-1] = 0;
                words[i] = malloc(sizeof(char)*strlen(w));
                strncpy(words[i], w, strlen(w));
                i++;
                words[i] = malloc(sizeof(char)*(strlen("\n")+1));
                strncpy(words[i], "\n", strlen("\n"));
                words[i][strlen("\n")] = 0;
                i++;
            } else {
                words[i] = malloc(sizeof(char)*strlen(w));
                strncpy(words[i], w, strlen(w));
                i++;
            }
        }
    }
    afree(lines);
    return words;
}

// Write words from array of strings to file path
int awrite(char *fpath, char **words) {
	FILE *f= fopen(fpath, "w");
	if (f == NULL) return 1;
    for (int i = 0; words[i]; ++i) {
        fputs(words[i], f);
        if (strncmp(words[i], "\n", MAX_WORD) &&
            strncmp(words[i+1], "\n", MAX_WORD))
        {
            fputs(" ", f);
        }
    }
    return 0;
}

// Free array of strings
void afree(char **arr) {
    for (int i = 0; arr[i]; ++i) free(arr[i]);
    free(arr);
}

// Print array of strings
void aprint(char **arr) {
    for (int i = 0; arr[i]; ++i) printf("%s", arr[i]);
}

// Trim words of any special characters
char *tword(char *w) {
    char *tw = malloc(sizeof(char)*MAX_WORD);
    int j = 0;
    for (int i = 0; w[i] != 0 && i < MAX_WORD; ++i) {
        if (isalnum(w[i])) {
            tw[j++] = w[i];
        }
    }
    return tw;
}

// Remove words from destination array that are found in source array
// and return array with the filtered words
char **afilter(char **dst, char **src) {
    int nw = NWORDS;
    char **fwords = malloc(sizeof(char*)*nw);
    int k = 0;
    for (int i = 0; dst[i]; ++i) {
        int isbanned = 0;
        for (int j = 0; src[j]; ++j) {
            if (!strncmp(dst[i], tword(src[j]), MAX_WORD)) {
                isbanned = 1;
                break;
            }
        }
        if (!isbanned) {
            if (k > nw-1) {
                nw *= 2;
                fwords = realloc(fwords,sizeof(char*)*nw);
            }
            char *w = dst[i];
            fwords[k] = malloc(sizeof(char)*strlen(w));
            strncpy(fwords[k], w, strlen(w));
            k++;
        }
    }
    return fwords;
}

int main(void) {
    char **bwords = rwords("./banned.txt");
    aprint(bwords);

    char **words = rwords("./to_redact.txt");
    aprint(words);

    char **fwords = afilter(words, bwords);
    aprint(fwords);

    int res = awrite("./redacted.txt", fwords);
    if (res) perror("Cannot open ./redacted.txt");

    afree(bwords);
    afree(words);
    afree(fwords);
	return 0;
}
